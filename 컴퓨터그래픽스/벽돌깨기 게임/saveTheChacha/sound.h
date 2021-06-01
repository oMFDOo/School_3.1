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
SND_ASYNC // ����߿��� ���α׷��� ��� ���ư�
SND_SYNC // ����� ������ ���α׷��� ���ư�
SND_FILENAME // �Ű������� ���� ������ �̸��� ���
SND_LOOP // �ݺ���� (SND_ASYNC�� ���� �����..)
SND_PURGE // �������
*/

// mic�� �̿��� ���� �Ҹ� ���
MCI_OPEN_PARMS openBgm;//������ �ε�
MCI_PLAY_PARMS playBgm;//������ ���
MCI_OPEN_PARMS openShuffleSound;//������ �ε�
MCI_PLAY_PARMS playShuffleSound;//������ ���

#define BGM "./sound/banana.wav" //BGM ��� ����

int dwID;
void playingBgm() {
	openBgm.lpstrElementName = TEXT(BGM); //���� ����
	openBgm.lpstrDeviceType = TEXT("mpegvideo"); //mp3 ����
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm);
	dwID = openBgm.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm); //���� �ݺ� ���
}

void playingShuffleSound(std::wstring name) {
	openShuffleSound.lpstrElementName = name.c_str(); //���� ����
	openShuffleSound.lpstrDeviceType = TEXT("mpegvideo"); //mp3 ����
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openShuffleSound);
	dwID = openShuffleSound.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&openShuffleSound); //������ �� �� ���
	Sleep(1800); //ȿ������ ����� ������ �����ߴٰ�
	mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //���� ��� ��ġ�� ó������ �ʱ�ȭ
}


void playSound(int track) {
	if (track == 1) {
		srand(time(NULL));
		track = 1 + (rand() % 6);
	}

	printf("Track : %d\n", track);


	switch (track) {
		// ���ӽ���
	case 0:
		playingBgm();
		playingShuffleSound(TEXT("./sound/help.wav"));
		break;
		// ����Ż��
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
	// ���� ����
	case 7 :
		playingShuffleSound(TEXT("./sound/gameOver.wav"));
		break;
	case 8:
		playingShuffleSound(TEXT("./sound/gameClear.wav"));
		break;
	}

}
