#pragma once
#include <windows.h>
#pragma comment(lib,"winmm") 
#include <mmsystem.h>

/*
SND_ASYNC // ����߿��� ���α׷��� ��� ���ư�
SND_SYNC // ����� ������ ���α׷��� ���ư�
SND_FILENAME // �Ű������� ���� ������ �̸��� ���
SND_LOOP // �ݺ���� (SND_ASYNC�� ���� �����..)
SND_PURGE // �������
*/

void playSound(int track) {
	switch (track) {
	case 0:
		PlaySound(TEXT("./sound/banana.wav"), 0, SND_ASYNC | SND_ALIAS);
		break;
	}
	
}
