package com.example.playGround.beanFindTest;

import com.example.playGround.AutoAppConfig;
import com.example.playGround.discount.DiscountPolicy;
import com.example.playGround.member.Grade;
import com.example.playGround.member.Member;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

import java.util.List;
import java.util.Map;

import static org.assertj.core.api.Assertions.assertThat;

public class OptionalBeanFindTest {

	@Test
	@DisplayName("할인 정책 옵션 선택 테스트")
	void findAllBean(){
		//given
		ApplicationContext ac = new AnnotationConfigApplicationContext(AutoAppConfig.class, DiscountService.class);
		DiscountService bean = ac.getBean(DiscountService.class);
		Member userA = new Member(1L, "userA", Grade.VIP);
		Member userB = new Member(2L, "userB", Grade.VIP);

		//when
		int discount1 = bean.discount(userA, 20000, "rateDiscountPolicy");
		int discount2 = bean.discount(userB, 20000, "fixDiscountPolicy");

		//then
		assertThat(discount1).isEqualTo(2000);
		assertThat(discount2).isEqualTo(1000);
	}

	static class DiscountService{
		private final Map<String, DiscountPolicy> policyMap;
		private final List<DiscountPolicy> discountPolicies;

		@Autowired
		public DiscountService(Map<String, DiscountPolicy> policyMap, List<DiscountPolicy> discountPolicies) {
			this.policyMap = policyMap;
			this.discountPolicies = discountPolicies;
			System.out.println("policyMap = " + policyMap);
			System.out.println("discountPolicies = " + discountPolicies);
		}

		public int discount(Member member, int price, String discountCode){
			DiscountPolicy discountPolicy = policyMap.get(discountCode);
			return discountPolicy.discount(member, price);
		}
	}
}
