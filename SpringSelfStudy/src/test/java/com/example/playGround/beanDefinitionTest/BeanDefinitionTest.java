package com.example.playGround.beanDefinitionTest;

import com.example.playGround.AppConfig;
import com.example.playGround.member.MemberService;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.config.BeanDefinition;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class BeanDefinitionTest {

	AnnotationConfigApplicationContext ac = new AnnotationConfigApplicationContext(AppConfig.class);

	@Test
	@DisplayName("빈을 사용하지 않았을 때는 객체가 여러개 생성된다.")
	void beaforeBean(){
		//given
		AppConfig appConfig = new AppConfig();

		//when
		MemberService memberService1 = appConfig.memberService();
		MemberService memberService2 = appConfig.memberService();

		//then
		Assertions.assertThat(memberService1).isNotSameAs(memberService2);
	}

	@Test
	@DisplayName("빈을 사용할 때는 객체가 하나만 생성된다.")
	void afterBean(){

		//when
		MemberService memberService1 = ac.getBean(MemberService.class);
		MemberService memberService2 = ac.getBean(MemberService.class);

		//then
		Assertions.assertThat(memberService1).isSameAs(memberService2);
	}

	@Test
	@DisplayName("모든 빈 출력.")
	void findAllBean(){
		String[] names = ac.getBeanDefinitionNames();
		for (String name : names) {
			Object bean = ac.getBean(name);
			System.out.println("bean = " + bean);
		}
	}

	@Test
	@DisplayName("내가 만든 모든 빈 출력.")
	void findAllDefindBean(){
		String[] names = ac.getBeanDefinitionNames();
		for (String name : names) {
			BeanDefinition beanDefinition = ac.getBeanDefinition(name);
			if (beanDefinition.getRole() == BeanDefinition.ROLE_APPLICATION)
				System.out.println("bean = " + name + " beanDefinition = " + beanDefinition);
		}
	}
}
