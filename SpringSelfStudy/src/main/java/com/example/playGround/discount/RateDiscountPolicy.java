package com.example.playGround.discount;

import com.example.playGround.member.Grade;
import com.example.playGround.member.Member;

public class RateDiscountPolicy implements DiscountPolicy{

	private int discountPersent = 10;

	@Override
	public int discount(Member member, int price) {
		if (member.getGrade() == Grade.VIP)
			return price * discountPersent / 100;
		return 0;
	}
}
