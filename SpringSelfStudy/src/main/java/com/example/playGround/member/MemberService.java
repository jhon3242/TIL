package com.example.playGround.member;

public interface MemberService {
	void join(Member member);
	Member findMember(Long memberId);
//	int getCount();
}
