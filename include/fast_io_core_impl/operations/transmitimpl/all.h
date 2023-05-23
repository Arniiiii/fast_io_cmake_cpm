#pragma once

namespace fast_io
{

namespace details
{

template<::fast_io::output_stream optstmtype,
	::fast_io::input_stream instmtype>
requires (sizeof(typename optstmtype::output_char_type)==sizeof(typename instmtype::input_char_type))
inline constexpr void transmit_all_main_impl(optstmtype optstm,instmtype instm,::fast_io::uintfpos_t totransmit)
{
/*
A dummy placeholder implementation
*/
	using input_char_type = typename instmtype::input_char_type;
	using output_char_type = typename optstmtype::output_char_type;
	constexpr
		::std::size_t bfsz{::fast_io::details::transmit_buffer_size_cache<sizeof(input_char_type)>};
	::fast_io::details::local_operator_new_array_ptr<input_char_type> newptr(bfsz);
	input_char_type *buffer_start{newptr.ptr};
	input_char_type *buffer_end{newptr.ptr+newptr.size};
	while(totransmit)
	{
		::std::size_t this_round{bfsz};
		if(totransmit<this_round)
		{
			this_round=static_cast<::std::size_t>(totransmit);
		}
		auto iter{buffer_start+this_round};
		::fast_io::operations::decay::read_all_decay(instm,buffer_start,iter);
		if constexpr(::std::same_as<output_char_type,input_char_type>)
		{
			::fast_io::operations::decay::write_all_decay(optstm,buffer_start,iter);
		}
		else
		{
			using output_char_type_may_alias_const_ptrtp
#if __has_cpp_attribute(__gnu__::__may_alias__)
			[[__gnu__::__may_alias__]]
#endif
			= output_char_type const*;
			::fast_io::operations::decay::write_all_decay(optstm,
				reinterpret_cast<output_char_type_may_alias_const_ptrtp>(buffer_start),
				reinterpret_cast<output_char_type_may_alias_const_ptrtp>(iter));
		}
		totransmit-=this_round;
	}
}

}

namespace operations
{

namespace decay
{

template<::fast_io::output_stream optstmtype,
	::fast_io::input_stream instmtype>
inline constexpr decltype(auto) transmit_all_decay(optstmtype optstm,instmtype instm,::fast_io::uintfpos_t totransmit)
{
	if constexpr(::fast_io::status_output_stream<optstmtype>)
	{
		return status_transmit_all_define(optstm,instm,totransmit);
	}
	else if constexpr(::fast_io::status_input_stream<instmtype>)
	{
		return status_transmit_all_define(optstm,instm,totransmit);
	}
	else if constexpr(::fast_io::details::mutex_unlocked_buffer_output_stream_impl<optstmtype>)
	{
		::fast_io::operations::stream_ref_lock_guard lg{output_stream_mutex_ref_impl(optstm)};
		return ::fast_io::operations::decay::transmit_all_decay(optstm,instm,totransmit);
	}
	else if constexpr(::fast_io::details::mutex_unlocked_buffer_input_stream_impl<instmtype>)
	{
		::fast_io::operations::stream_ref_lock_guard lg{input_stream_mutex_ref_impl(instm)};
		return ::fast_io::operations::decay::transmit_all_decay(optstm,instm,totransmit);
	}
	else
	{
		return ::fast_io::details::transmit_all_main_impl(optstm,instm,totransmit);
	}
}

}

template<typename optstmtype,typename instmtype>
inline constexpr decltype(auto) transmit_all(optstmtype &&optstm,instmtype &&instm,::fast_io::uintfpos_t totransmit)
{
	return ::fast_io::operations::decay::transmit_all_decay(::fast_io::manipulators::output_stream_ref(optstm),
		::fast_io::manipulators::input_stream_ref(instm),totransmit);
}

}

}
