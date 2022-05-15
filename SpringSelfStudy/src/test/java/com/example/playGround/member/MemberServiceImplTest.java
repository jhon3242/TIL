package com.example.playGround.member;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.*;

class MemberServiceImplTest {

	MemberService memberService = new MemberServiceImpl();

	@Test
	@DisplayName("회원 가입이 문제가 없어야 한다.")
	void join() {
		// given
		Member member = new Member(1L, "memberA", Grade.VIP);
		// when
		memberService.join(member);
		Member findMember = memberService.findMember(1L);
		// then
		assertThat(findMember).isEqualTo(member);
	}

	@Test
	@DisplayName("회원 찾기에 문제가 없어야 한다.")
	void findMember() {
		//given
		Member memberA = new Member(1L, "memberA", Grade.VIP);
		Member memberB = new Member(2L, "memberB", Grade.VIP);
		Member memberC = new Member(3L, "memberC", Grade.VIP);

		//when
		memberService.join(memberA);
		memberService.join(memberB);
		memberService.join(memberC);

		//then
		Member member1 = memberService.findMember(1L);
		Member member2 = memberService.findMember(2L);
		Member member3 = memberService.findMember(3L);
		assertThat(member1).isSameAs(memberA);
		assertThat(member2).isSameAs(memberB);
		assertThat(member3).isSameAs(memberC);
	}

//	@Test
//	@DisplayName("회원 등록된 수 일치해야한다.")
//	void matchCount(){
//		//given
//		Member mamberA = new Member(1L, "mamberA", Grade.VIP);
//		Member mamberB = new Member(2L, "mamberB", Grade.VIP);
//		Member mamberC = new Member(3L, "mamberC", Grade.VIP);
//
//		//when
//		memberService.join(mamberA);
//		memberService.join(mamberB);
//		memberService.join(mamberC);
//
//		//then
//		memberService.
//	}
}