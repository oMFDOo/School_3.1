#pragma once
#include <windows.h>
#pragma comment(lib,"winmm.lib") 
#include <mmsystem.h>
#include <Digitalv.h>
#include <stdlib.h>
#include <time.h>
#include<stdio.h>
#include<Windows.h>
#include<string>

/*
SND_ASYNC // 재생중에도 프로그램이 계속 돌아감
SND_SYNC // 재생이 끝나야 프로그램이 돌아감
SND_FILENAME // 매개변수가 사운드 파일의 이름일 경우
SND_LOOP // 반복재생 (SND_ASYNC와 같이 써야함..)
SND_PURGE // 재생중지
*/

// mic를 이용한 동시 소리 재생
MCI_OPEN_PARMS openBgm;//파일을 로드
MCI_PLAY_PARMS playBgm;//파일을 재생
MCI_OPEN_PARMS openShuffleSound;//파일을 로드
MCI_PLAY_PARMS playShuffleSound;//파일을 재생

#define BGM "./sound/banana.wav" //BGM 경로 지정

int dwID;
void playingBgm() {
	openBgm.lpstrElementName = TEXT(BGM); //파일 오픈
	openBgm.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm);
	dwID = openBgm.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm); //음악 반복 재생
}

void playingShuffleSound(std::wstring name) {
	openShuffleSound.lpstrElementName = name.c_str(); //파일 오픈
	openShuffleSound.lpstrDeviceType = TEXT("mpegvideo"); //mp3 형식
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openShuffleSound);
	dwID = openShuffleSound.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openShuffleSound); //음악을 한 번 재생
	Sleep(1800); //효과음이 재생될 때까지 정지했다가
	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
}


void playSound(int track) {
	if (track == 1) {
		srand(time(NULL));
		track = 1 + (rand() % 6);
	}

	printf("Track : %d\n", track);


	switch (track) {
		// 게임시작
	case 0:
		playingBgm();
		playingShuffleSound(TEXT("./sound/help.wav"));
		break;
		// 차차탈출
	case 1:
		playingShuffleSound(TEXT("./sound/freedom.wav"));
		break;
	case 2:
		playingShuffleSound(TEXT("./sound/inBlock.wav"));
		break;
	case 3:
		playingShuffleSound(TEXT("./sound/thanks1.wav"));
		break;
	case 4:
		playingShuffleSound(TEXT("./sound/thanks2.wav"));
		break;
	case 5:
		playingShuffleSound(TEXT("./sound/workOut.wav"));
		break;
	case 6:
		playingShuffleSound(TEXT("./sound/huu.wav")); 
		break;
	// 게임 종료
	case 7 :
		playingShuffleSound(TEXT("./sound/gameOver.wav"));
		break;
	case 8:
		playingShuffleSound(TEXT("./sound/gameClear.wav"));
		break;
	}

}
