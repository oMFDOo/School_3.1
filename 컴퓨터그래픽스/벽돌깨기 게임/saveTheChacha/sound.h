#pragma once
#include <windows.h>
#pragma comment(lib,"winmm") 
#include <mmsystem.h>

/*
SND_ASYNC // 재생중에도 프로그램이 계속 돌아감
SND_SYNC // 재생이 끝나야 프로그램이 돌아감
SND_FILENAME // 매개변수가 사운드 파일의 이름일 경우
SND_LOOP // 반복재생 (SND_ASYNC와 같이 써야함..)
SND_PURGE // 재생중지
*/

void playSound(int track) {
	switch (track) {
	case 0:
		PlaySound(TEXT("./sound/banana.wav"), 0, SND_ASYNC | SND_ALIAS);
		break;
	}
	
}
