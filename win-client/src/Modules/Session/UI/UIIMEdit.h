 /*******************************************************************************
 *  @file      UIIMEdit.h 2014\8\19 13:18:10 $
 *  @author    ���<dafo@mogujie.com>
 *  @brief     
 ******************************************************************************/

#ifndef UIIMEDIT_3DC89058_72C4_4225_A6EB_0F39D182913F_H__
#define UIIMEDIT_3DC89058_72C4_4225_A6EB_0F39D182913F_H__


#include "DuiLib/UIlib.h"
using namespace DuiLib;
#include "GlobalDefine.h"


#define UIIMEdit_MSGTYPE_TEXTCHANGED (_T("UIIMEdit_TEXT_Changed"))


/******************************************************************************/

/**
 * The class <code>UIIMEdit</code> 
 *
 */
namespace
{
	const CString CS_SPLIT_CODE_START = _T("&$#@~^@[{:");
	const CString CS_SPLIT_CODE_END = _T(":}]&$~@#@");
	const CString CS_SPLIT_CODE_FILE_START = _T("&$#@~^@dkfile[{:");
	const CString CS_SPLIT_CODE_FILE_END = _T(":}]filedk&$~@#@");
}
struct ST_picData
{
	UINT32	nPos;
	CString strLocalPicPath;
	CString strNetPicPath;
};
struct ST_fileData
{
	UINT32 nPos;
	CString strLocalFilePath;
	CString strNetFilePath;
	CString strFileName;
};
class MixedMsg
{
public:
	MixedMsg();
	BOOL SetNetWorkPicPath(IN CString strLocalPicPath, IN CString strNetPicPath);
	BOOL SucceedToGetAllNetWorkPic();
	CString MakeMixedLocalMSG();
	CString MakeMixedNetWorkMSG();
	BOOL IsPureTextMsg();
	static CString AddPicTeg2Pic(IN CString picPath);
	static CString AddFileTeg2File(IN CString filePath);
public:
	CString						m_strTextData;					//����
	std::vector<ST_picData>		m_picDataVec;				//ͼƬ���������е�λ�ã�ͼƬ�ı���·����ͼƬ������·��
	std::vector<ST_fileData>	m_fileDataVec;				//�ļ����������е�λ�ã��ļ��ı���·�����ļ�������·��
private:
	UINT32					m_nSetNetWorkPathSuccTime;	//�ɹ���õ�ͼƬ�Ĵ���
};


class UIIMEdit :public CRichEditUI
{
public:
    /** @name Constructors and Destructor*/

    //@{
    /**
     * Constructor 
     */
    UIIMEdit();
    /**
     * Destructor
     */
    virtual ~UIIMEdit();
    //@}

public:
	virtual void DoInit();
	LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled);
	BOOL GetContent(OUT	MixedMsg& mixMsg);
	virtual LPVOID GetInterface(LPCTSTR pstrName);
	virtual LPCTSTR GetClass() const;
	virtual bool OnTxViewChanged();
	int	GetObjectPos();
	void InsertImage(BSTR bstrFileName, SIZE size, BOOL isGif);
	HRESULT GetNewStorage(LPSTORAGE* ppStg);
	void	GetObjectInfo(IRichEditOle *pIRichEditOle);
	void ReleaseAllGif();
	BOOL GetPicPosAndPathbyOrder(IN UInt32 nOrder,OUT UInt32& nPos,OUT CString& path );

private:
	void _ImEditPaste();
	BOOL _SaveFile(IN HBITMAP hbitmap, OUT CString& strFilePath);
	HBITMAP _LoadAnImage(IN CString filePath);
	
private:
	CString                     m_strImagePath;
};
/******************************************************************************/
#endif// UIIMEDIT_3DC89058_72C4_4225_A6EB_0F39D182913F_H__
