package com.example.playGround.beanFindTest;

import com.example.playGround.AppConfig;
import com.example.playGround.member.MemberService;
import com.example.playGround.member.MemberServiceImpl;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.NoSuchBeanDefinitionException;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

import static org.junit.jupiter.api.Assertions.assertThrows;

public class BasicBeanFindTest {

	AnnotationConfigApplicationContext ac = new AnnotationConfigApplicationContext(AppConfig.class);

	@Test
	@DisplayName("빈 이름으로 조회 테스트")
	void findBeanByName(){
		MemberService memberService = ac.getBean("memberService", MemberService.class);
		Assertions.assertThat(memberService).isInstanceOf(MemberServiceImpl.class);
	}

	@Test
	@DisplayName("이름없이 타입으로 조회 테스트")
	void findBeanByType(){
		MemberService memberService = ac.getBean(MemberService.class);
		Assertions.assertThat(memberService).isInstanceOf(MemberServiceImpl.class);
	}

	@Test
	@DisplayName("구체 타입으로 조회 테스트")
	void findBeanByImplType(){
		MemberService memberService = ac.getBean("memberService", MemberServiceImpl.class);
		Assertions.assertThat(memberService).isInstanceOf(MemberServiceImpl.class);
	}

	@Test
	@DisplayName("없는 빈 이름으로 조회 테스트")
	void findBeanByNoName(){
//		ac.getBean("no");  -> NoSuchBeanDefinitionException 에러 발생
		assertThrows(NoSuchBeanDefinitionException.class,
				() -> ac.getBean("no", MemberService.class));

	}
}
