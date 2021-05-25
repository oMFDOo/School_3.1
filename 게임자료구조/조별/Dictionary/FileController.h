#pragma once
class FileOrder {
public:
	FileOrder() :isSave(false) {};
	// 모드 입력을 받고 알맞은 함수 기능 실행
	void modeSet();
	// ‘i’: - 입력 모드 사용자가 단어와 의미를 입력하여 이진탐색트리에 노드를 추가
	void insertMode();
	// ‘d’: 삭제 모드 사용자 입력한 사전을 삭제하는 것
	void deleteMode();
	// ‘s’: 탐색 모드 사용자로부터 영어 단어를 입력받아 의미를 화면에 출력
	void searchMode();
	// ‘p’: 출력 모드 모든 단어와 의미를 화면에 출력
	void printMode();
	// ‘w’: 저장 모드 단어의 내용을 파일로 저장 (프로그래머 지정 파일)
	void writeMode();
	// ‘q’: 종료 모드 단어장 애플리케이션 종료
	void quitMode();
private:
	bool isSave;
};