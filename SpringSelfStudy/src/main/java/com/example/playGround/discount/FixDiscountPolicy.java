package com.example.playGround.discount;

import com.example.playGround.member.Grade;
import com.example.playGround.member.Member;

public class FixDiscountPolicy implements DiscountPolicy{

	@Override
	public int discount(Member member, int price) {
		if (member.getGrade() == Grade.VIP)
			return 1000;
		else
			return 0;
	}
}
