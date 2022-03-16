// MySocket.cpp: файл реализации
//

#include "stdafx.h"
#include "SnopokLR_8.h"
#include "MySocket.h"
#include "SnopokLR_8Dlg.h"


// CMySocket

CMySocket::CMySocket()
{
}

CMySocket::~CMySocket()
{
}


// функции-члены CMySocket
void CMySocket::SetParent(CDialog *pWnd) { m_pWnd = pWnd; }
void CMySocket::OnAccept(int nErrorCode) {
	if (nErrorCode == 0) ((CSnopokLR_8Dlg*)m_pWnd)->OnAccept();
	CAsyncSocket::OnAccept(nErrorCode);
}
void CMySocket::OnClose(int nErrorCode) {
	if (nErrorCode == 0) ((CSnopokLR_8Dlg*)m_pWnd)->OnClose();
	CAsyncSocket::OnClose(nErrorCode);
}
void CMySocket::OnConnect(int nErrorCode) {
	if (nErrorCode == 0) ((CSnopokLR_8Dlg*)m_pWnd)->OnConnect();
	CAsyncSocket::OnConnect(nErrorCode);
}
void CMySocket::OnReceive(int nErrorCode) {
	if (nErrorCode == 0) ((CSnopokLR_8Dlg*)m_pWnd)->OnReceive();
	CAsyncSocket::OnReceive(nErrorCode);
}
void CMySocket::OnSend(int nErrorCode) {
	if (nErrorCode == 0) ((CSnopokLR_8Dlg*)m_pWnd)->OnBnClickedOperationEquals();
	CAsyncSocket::OnSend(nErrorCode);
}