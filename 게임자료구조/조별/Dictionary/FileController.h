#pragma once
class FileOrder {
public:
	FileOrder() :isSave(false) {};
	// ��� �Է��� �ް� �˸��� �Լ� ��� ����
	void modeSet();
	// ��i��: - �Է� ��� ����ڰ� �ܾ�� �ǹ̸� �Է��Ͽ� ����Ž��Ʈ���� ��带 �߰�
	void insertMode();
	// ��d��: ���� ��� ����� �Է��� ������ �����ϴ� ��
	void deleteMode();
	// ��s��: Ž�� ��� ����ڷκ��� ���� �ܾ �Է¹޾� �ǹ̸� ȭ�鿡 ���
	void searchMode();
	// ��p��: ��� ��� ��� �ܾ�� �ǹ̸� ȭ�鿡 ���
	void printMode();
	// ��w��: ���� ��� �ܾ��� ������ ���Ϸ� ���� (���α׷��� ���� ����)
	void writeMode();
	// ��q��: ���� ��� �ܾ��� ���ø����̼� ����
	void quitMode();
private:
	bool isSave;
};