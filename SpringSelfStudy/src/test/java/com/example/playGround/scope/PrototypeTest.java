package com.example.playGround.scope;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Scope;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

public class PrototypeTest {

	@Test
	@DisplayName("프로토타입 스코프")
	void PrototypeFindTest(){
		AnnotationConfigApplicationContext ac = new AnnotationConfigApplicationContext(PrototypeBean.class);
		PrototypeBean prototypeBean1 = ac.getBean(PrototypeBean.class);
		PrototypeBean prototypeBean2 = ac.getBean(PrototypeBean.class);

		System.out.println("prototypeBean1 = " + prototypeBean1);
		System.out.println("prototypeBean2 = " + prototypeBean2);

		Assertions.assertThat(prototypeBean1).isNotSameAs(prototypeBean2);
		ac.close(); // 실행 안됨 따라서 직접 종료해줘야 함
		prototypeBean1.close();
		prototypeBean2.close();
	}

	@Scope("prototype")
	static class PrototypeBean{
		@PostConstruct
		void init(){
			System.out.println("PrototypeBean.init");
		}

		@PreDestroy
		void close(){
			System.out.println("PrototypeBean.close");
		}
	}
}
