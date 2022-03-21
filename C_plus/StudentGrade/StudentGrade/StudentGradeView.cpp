
// StudentGradeView.cpp: CStudentGradeView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "StudentGrade.h"
#endif

#include "StudentGradeDoc.h"
#include "StudentGradeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStudentGradeView

IMPLEMENT_DYNCREATE(CStudentGradeView, CView)

BEGIN_MESSAGE_MAP(CStudentGradeView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CStudentGradeView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CStudentGradeView 构造/析构

CStudentGradeView::CStudentGradeView() noexcept
{
	// TODO: 在此处添加构造代码

}

CStudentGradeView::~CStudentGradeView()
{
}

BOOL CStudentGradeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CStudentGradeView 绘图

void CStudentGradeView::OnDraw(CDC* /*pDC*/)
{
	CStudentGradeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CStudentGradeView 打印


void CStudentGradeView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CStudentGradeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CStudentGradeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CStudentGradeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CStudentGradeView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CStudentGradeView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CStudentGradeView 诊断

#ifdef _DEBUG
void CStudentGradeView::AssertValid() const
{
	CView::AssertValid();
}

void CStudentGradeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStudentGradeDoc* CStudentGradeView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStudentGradeDoc)));
	return (CStudentGradeDoc*)m_pDocument;
}
#endif //_DEBUG


// CStudentGradeView 消息处理程序
