package com.example.playGround.web;


import com.example.playGround.common.MyLogger;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import javax.servlet.http.HttpServletRequest;

@Controller
@RequiredArgsConstructor
public class LogDemoController {

	private final LogDemoService logDemoService;
	private final MyLogger myLogger;

	@GetMapping("log-demo")
	@ResponseBody
	public String logDemo(HttpServletRequest request){
		String rURL = request.getRequestURL().toString();
		myLogger.setRequestUrl(rURL);
		myLogger.log("controll test");
		logDemoService.logic("testId");
		return "OK";
	}
}
