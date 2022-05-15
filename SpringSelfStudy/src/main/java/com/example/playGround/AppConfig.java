package com.example.playGround;

import com.example.playGround.discount.DiscountPolicy;
import com.example.playGround.discount.RateDiscountPolicy;
import com.example.playGround.member.MemberRepository;
import com.example.playGround.member.MemberService;
import com.example.playGround.member.MemberServiceImpl;
import com.example.playGround.member.MemoryMemberRepository;
import com.example.playGround.order.OrderService;
import com.example.playGround.order.OrderServiceImpl;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class AppConfig {

	@Bean
	public MemberRepository memberRepository() {
		return new MemoryMemberRepository();
	}

	@Bean
	public MemberService memberService(){
		return new MemberServiceImpl(new MemoryMemberRepository());
	}

	@Bean
	public DiscountPolicy discountPolicy(){
		return new RateDiscountPolicy();
	}

	@Bean
	public OrderService orderService(){
		return new OrderServiceImpl();
	}
}
