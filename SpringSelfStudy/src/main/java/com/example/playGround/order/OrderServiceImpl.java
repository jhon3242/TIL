package com.example.playGround.order;

import com.example.playGround.discount.DiscountPolicy;
import com.example.playGround.discount.FixDiscountPolicy;
import com.example.playGround.member.Member;
import com.example.playGround.member.MemberRepository;
import com.example.playGround.member.MemoryMemberRepository;

public class OrderServiceImpl implements OrderService{

	private MemberRepository memberRepository = new MemoryMemberRepository();
	private DiscountPolicy discountPolicy = new FixDiscountPolicy();

	@Override
	public Order createOrder(Long memberId, String itemName, int itemPrice) {

		Member member = memberRepository.findById(memberId);
		int discountPrice = discountPolicy.discount(member, itemPrice);

		return new Order(memberId, itemName, itemPrice, discountPrice);
	}
}
