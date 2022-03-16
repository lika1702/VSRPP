#pragma once

// конечный объект команды CMySocket

class CMySocket : public CAsyncSocket
{
private:
	CDialog* m_pWnd;
protected:
	void OnAccept(int nErrorCode);
	void OnClose(int nErrorCode);
	void OnConnect(int nErrorCode);
	void OnReceive(int nErrorCode);
	void OnSend(int nErrorCode);
public:
	CMySocket();
	virtual ~CMySocket();
	void SetParent(CDialog *pWnd);
};


