package com.example.playGround.scope;

import lombok.RequiredArgsConstructor;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Scope;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import static org.assertj.core.api.Assertions.assertThat;

public class SingletonWithPrototypeTest2 {


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
		assertThat(count2).isEqualTo(1);
	}

	@Scope("singleton")
	static class SingletonBean{

		@Autowired
		private ApplicationContext ac;

		public int logic(){
			PrototypeBean prototypeBean = ac.getBean(PrototypeBean.class);
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
