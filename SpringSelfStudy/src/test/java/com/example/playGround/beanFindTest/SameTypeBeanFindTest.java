package com.example.playGround.beanFindTest;

import com.example.playGround.AppConfig;
import com.example.playGround.discount.DiscountPolicy;
import com.example.playGround.discount.FixDiscountPolicy;
import com.example.playGround.discount.RateDiscountPolicy;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.NoUniqueBeanDefinitionException;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Bean;

import java.util.Map;

import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.assertThrows;

public class SameTypeBeanFindTest {
	ApplicationContext ac = new AnnotationConfigApplicationContext(SameBeanConfig.class);

	@Test
	@DisplayName("타입으로 조회시 같은 타입 빈 중복이면 오류")
	void sameTypeBeanFindByType(){
//		ac.getBean(DiscountPolicy.class);  // -> NoUniqueBeanDefinitionException 에러 발생
		assertThrows(NoUniqueBeanDefinitionException.class,
				() -> ac.getBean(DiscountPolicy.class));
	}

	@Test
	@DisplayName("이름으로 조회시 같은 타입 빈 중복이여도 정상")
	void sameTypeBeanFindByName(){
		DiscountPolicy fixDiscountPolicy = ac.getBean("fixDiscountPolicy", DiscountPolicy.class);
		assertThat(fixDiscountPolicy).isInstanceOf(DiscountPolicy.class);

		DiscountPolicy rateDiscountPolicy = ac.getBean("rateDiscountPolicy", DiscountPolicy.class);
		assertThat(rateDiscountPolicy).isInstanceOf(DiscountPolicy.class);
	}

	@Test
	@DisplayName("특정 타입 빈 모두 출력")
	void putBeanByType(){
		Map<String, DiscountPolicy> beansOfType = ac.getBeansOfType(DiscountPolicy.class);
		for (String key : beansOfType.keySet()) {
			System.out.println("key = " + key + " value = " + beansOfType.get(key));
		}
		System.out.println("beansOfType = " + beansOfType);
		assertThat(beansOfType.size()).isEqualTo(2);
	}

	static class SameBeanConfig{

		@Bean
		public DiscountPolicy rateDiscountPolicy(){
			return new RateDiscountPolicy();
		}

		@Bean
		public DiscountPolicy fixDiscountPolicy(){
			return new FixDiscountPolicy();
		}
	}
}
