package com.example.playGround.scope;

import lombok.RequiredArgsConstructor;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Scope;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import static org.assertj.core.api.Assertions.assertThat;

public class SingletonWithPrototypeTest1 {

	@Test
	@DisplayName("프로토타입 2번 호출시 객체 2개가 생성된다.")
	void prototypeFind(){
		AnnotationConfigApplicationContext ac = new AnnotationConfigApplicationContext(PrototypeBean.class);
		PrototypeBean prototypeBean1 = ac.getBean(PrototypeBean.class);
		PrototypeBean prototypeBean2 = ac.getBean(PrototypeBean.class);

		prototypeBean1.addCount();
		prototypeBean2.addCount();

		assertThat(prototypeBean1.getCount()).isEqualTo(1);
		assertThat(prototypeBean2.getCount()).isEqualTo(1);
	}

	@Test
	void SingletonWithPrototype(){

		AnnotationConfigApplicationContext ac =
				new AnnotationConfigApplicationContext(SingletonBean.class, PrototypeBean.class);
		SingletonBean singletonBean1 = ac.getBean(SingletonBean.class);
		SingletonBean singletonBean2 = ac.getBean(SingletonBean.class);

		//then
		int count1 = singletonBean1.logic();
		assertThat(count1).isEqualTo(1);
		int count2 = singletonBean2.logic();
		assertThat(count2).isEqualTo(2);
	}

	@Scope("singleton")
	@RequiredArgsConstructor
	static class SingletonBean{
		private final PrototypeBean prototypeBean;

		public int logic(){
			prototypeBean.addCount();
			int count = prototypeBean.getCount();
			return count;
		}
	}

	@Scope("prototype")
	static class PrototypeBean{
		private int count;

		public int getCount() {
			return count;
		}

		public void addCount(){
			count += 1;
		}

		@PostConstruct
		public void init(){
			System.out.println("PrototypeBean.init " + this);
		}

		@PreDestroy
		public void close(){
			System.out.println("PrototypeBean.close " + this);
		}
	}

}
