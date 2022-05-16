package com.example.playGround.scan;

import com.example.playGround.AutoAppConfig;
import com.example.playGround.member.MemberService;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

import static org.assertj.core.api.Assertions.assertThat;

public class AutoAppConfigTest {

	@Test
	@DisplayName("컴포넌트 스캔이 잘 동작한다")
	void basicTest(){
		ApplicationContext ac = new AnnotationConfigApplicationContext(AutoAppConfig.class);

		MemberService bean = ac.getBean(MemberService.class);
		assertThat(bean).isInstanceOf(MemberService.class);
	}
}
