package com.example.playGround.discount;

import com.example.playGround.AppConfig;
import com.example.playGround.member.Grade;
import com.example.playGround.member.Member;
import com.example.playGround.member.MemberService;
import com.example.playGround.member.MemberServiceImpl;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.*;

class RateDiscountPolicyTest {

	private MemberService memberService;
	private DiscountPolicy discountPolicy;

	@BeforeEach
	public void beforeEach() {
		AppConfig appConfig = new AppConfig();
		memberService = appConfig.memberService();
		discountPolicy = appConfig.discountPolicy();
	}



	@Test
	@DisplayName("VIP 이면 10% 할인이 되어야 한다.")
	void vipDiscount(){
		//given
		Member member1 = new Member(1L, "member1", Grade.VIP);

		//when
		memberService.join(member1);
		int discount1 = discountPolicy.discount(member1, 20000);

		//then
		assertThat(discount1).isEqualTo(2000);
	}

	@Test
	@DisplayName("VIP 가 아니면 할인이 없다.")
	void noVipDiscount(){
		//given
		Member member2 = new Member(2L, "member2", Grade.BASIC);

		//when
		memberService.join(member2);
		int discount2 = discountPolicy.discount(member2, 20000);

		//then
		assertThat(discount2).isEqualTo(0);
	}
}