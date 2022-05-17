package com.example.playGround.lifecycle;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.ConfigurableApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

public class BeanLifecycleTest {

	@Test
	@DisplayName("빈 생명주기 확인")
	void lifeCycleTest(){
		ConfigurableApplicationContext ac = new AnnotationConfigApplicationContext(LifeCycleConfig.class);
		NetworkClient client = ac.getBean(NetworkClient.class);
		ac.close();
	}

	@Configuration
	static class LifeCycleConfig{

		@Bean()
		public NetworkClient networkClient(){
			NetworkClient networkClient = new NetworkClient();
			networkClient.setUrl("https://hello-spring.dev");
			return networkClient;
		}
	}
}
