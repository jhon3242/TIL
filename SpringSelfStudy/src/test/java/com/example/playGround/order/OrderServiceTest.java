package com.example.playGround.order;

import com.example.playGround.AppConfig;
import com.example.playGround.discount.FixDiscountPolicy;
import com.example.playGround.member.*;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class OrderServiceTest {
	private MemberService memberService;
	private OrderService orderService;

	@BeforeEach
	public void beforeEach(){
		AppConfig appConfig = new AppConfig();
		memberService = appConfig.memberService();
		orderService = appConfig.orderService();
	}

	@Test
	@DisplayName("주문 생성시 할인 금액이 문제없다.")
	void ceateOrder(){
		//given
		Long memberId = 1L;

		//when
		Member member = new Member(memberId, "userA", Grade.VIP);
		memberService.join(member);
		Order order = orderService.createOrder(memberId, "itemA", 10000);

		//then
		Assertions.assertThat(order.getDiscountPrice()).isEqualTo(1000);
	}
}