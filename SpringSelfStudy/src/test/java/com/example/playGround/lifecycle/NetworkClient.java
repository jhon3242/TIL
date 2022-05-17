package com.example.playGround.lifecycle;

import org.springframework.beans.factory.DisposableBean;
import org.springframework.beans.factory.InitializingBean;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;
import javax.naming.Context;
import javax.naming.NamingException;
import javax.naming.spi.InitialContextFactory;
import java.util.Hashtable;

public class NetworkClient {
	private String url;

	public void setUrl(String url) {
		this.url = url;
	}

	public NetworkClient() {
		System.out.println("생성자 호출 url = " + url);
	}

	public void connect(){
		System.out.println("connect : " + url);
	}
	
	public void call(String message){
		System.out.println("call : " + url + " message = " + message);
	}

	public void disconnect(){
		System.out.println("close : " + url);
	}


	@PostConstruct
	public void init() {
		connect();
		call("초기화 연결 메시지");
	}

	@PreDestroy
	public void close() {
		disconnect();
	}
}
