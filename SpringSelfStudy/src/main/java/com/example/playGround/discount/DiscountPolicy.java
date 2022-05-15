package com.example.playGround.discount;

import com.example.playGround.member.Member;

public interface DiscountPolicy {
	int discount(Member member, int price);
}
