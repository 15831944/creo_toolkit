#include "StdAfx.h"

ProUIDashboardShowOptions dashboard_options = NULL;
ProUIDashboardPageOptions mainpage_options = NULL;
ProUIDashboardPageOptions *slideup_panels = NULL;

void mainpage_ok_btn(char *dialog, char *component, ProAppData appdata)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	ProError status;
	ProUIDashboard db;
	AfxMessageBox(_T("�������ȷ����ť"));

	status = ProUIDashboardpageDashboardGet(appdata, &db);
	status = ProUIDashboardDestroy(db);
}

void mainpage_cancel_btn(char *dialog, char *component, ProAppData appdata)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	ProError status;
	ProUIDashboard db;
	AfxMessageBox(_T("�������ȡ����ť"));

	status = ProUIDashboardpageDashboardGet(appdata, &db);
	status = ProUIDashboardDestroy(db);
}

void mainpage_msg_btn(char *dialog, char *component, ProAppData appdata)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	AfxMessageBox(_T("�������mainpage�Ĳ��԰�ť"));
}

void slide1_msg_btn(char *dialog, char *component, ProAppData appdata)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	AfxMessageBox(_T("�������slide1�Ĳ��԰�ť"));
}

static ProError MainPageNotification(ProUIDashboardPage page, ProUIDashboardPageEventType event_type, ProAppData appdata)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	ProError status;
	char *component_name;
	char *name;
	switch (event_type)
	{
	case PRO_UI_DASHBOARD_PAGE_CREATE:
		status = ProUIDashboardpageComponentnameGet(page, "ok_btn", &component_name);
		status = ProUIDashboardpageDevicenameGet(page, &name);
		status = ProUIPushbuttonActivateActionSet(name, component_name, (ProUIAction)(mainpage_ok_btn), page);
		status = ProStringFree(component_name);
		status = ProStringFree(name);

		status = ProUIDashboardpageComponentnameGet(page, "cancel_btn", &component_name);
		status = ProUIDashboardpageDevicenameGet(page, &name);
		status = ProUIPushbuttonActivateActionSet(name, component_name, (ProUIAction)(mainpage_cancel_btn), page);
		status = ProStringFree(component_name);
		status = ProStringFree(name);

		status = ProUIDashboardpageComponentnameGet(page, "msg_btn", &component_name);
		status = ProUIDashboardpageDevicenameGet(page, &name);
		status = ProUIPushbuttonActivateActionSet(name, component_name, (ProUIAction)(mainpage_msg_btn), page);
		status = ProStringFree(component_name);
		status = ProStringFree(name);

		AfxMessageBox(_T("MainPage_PRO_UI_DASHBOARD_PAGE_CREATE"));
		break;
	case PRO_UI_DASHBOARD_PAGE_SHOW:
		AfxMessageBox(_T("MainPage_PRO_UI_DASHBOARD_PAGE_SHOW"));
		break;
	case PRO_UI_DASHBOARD_PAGE_HIDE:
		AfxMessageBox(_T("MainPage_PRO_UI_DASHBOARD_PAGE_HIDE"));
		break;
	case PRO_UI_DASHBOARD_PAGE_DESTROY:
		AfxMessageBox(_T("MainPage_PRO_UI_DASHBOARD_PAGE_DESTROY"));
		break;
	default:
		break;
	}
	return PRO_TK_NO_ERROR;
}

static ProError DashboardMainPageSetup(ProAppData data, ProUIDashboardPage *page_options, char *page_name, char *resource_name)
{
	ProUIDashboardPage opts;
	ProError status;
	status = ProUIDashboardpageoptionsAlloc(page_name, resource_name, data, &opts);
	status = ProUIDashboardpageoptionsNotificationSet(opts, (ProUIDashboardpageCallbackFunction)MainPageNotification, data);
	*page_options = opts;
	return PRO_TK_NO_ERROR;
}

static ProError Slide1Notification(ProUIDashboardPage page, ProUIDashboardPageEventType event_type, ProAppData appdata)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	ProError status;
	char *component_name;
	char *name;
	switch (event_type)
	{
	case PRO_UI_DASHBOARD_PAGE_CREATE:
		status = ProUIDashboardpageTitleSet(page, _T("����slide"));
		status = ProUIDashboardpageComponentnameGet(page, "msg_btn", &component_name);
		status = ProUIDashboardpageDevicenameGet(page, &name);
		status = ProUIPushbuttonActivateActionSet(name, component_name, (ProUIAction)(slide1_msg_btn), page);
		status = ProStringFree(component_name);
		status = ProStringFree(name);
		AfxMessageBox(_T("Slide1_PRO_UI_DASHBOARD_PAGE_CREATE"));
		break;
	case PRO_UI_DASHBOARD_PAGE_SHOW:
		AfxMessageBox(_T("Slide1_PRO_UI_DASHBOARD_PAGE_SHOW"));
		break;
	case PRO_UI_DASHBOARD_PAGE_HIDE:
		AfxMessageBox(_T("Slide1_PRO_UI_DASHBOARD_PAGE_HIDE"));
		break;

	case PRO_UI_DASHBOARD_PAGE_DESTROY:
		AfxMessageBox(_T("Slide1_PRO_UI_DASHBOARD_PAGE_DESTROY"));
		break;
	default:
		break;
	}
	return PRO_TK_NO_ERROR;
}

static ProError DashboardSlidePageSetup(ProAppData data, ProUIDashboardPage *page_options)
{
	ProUIDashboardPage opts;
	ProError status;
	status = ProUIDashboardpageoptionsAlloc("����slidename", "slide1", data, &opts);
	status = ProUIDashboardpageoptionsNotificationSet(opts, (ProUIDashboardpageCallbackFunction)Slide1Notification, data);
	*page_options = opts;
	return PRO_TK_NO_ERROR;
}

void CleanOptions()
{
	ProError status;
	if (mainpage_options != NULL)
	{
		status = ProUIDashboardpageoptionsFree(mainpage_options);
		mainpage_options = NULL;
	}

	if (dashboard_options != NULL)
	{
		status = ProUIDashboardshowoptionsFree(dashboard_options);
		dashboard_options = NULL;
	}

	if (slideup_panels != NULL)
	{
		status = ProArrayFree(slideup_panels);
		slideup_panels = NULL;
	}
}

static ProError DashboardNotification(ProUIDashboard dashboard, ProUIDashboardEventType event_type, ProAppData appdata)
{
	switch (event_type)
	{
	case PRO_UI_DASHBOARD_CREATE:
		//status = ProUIDashboardBitmapSet(dashboard, "dash_done");
		AfxMessageBox(_T("DashboardNotification_PRO_UI_DASHBOARD_PAGE_CREATE"));
		break;
	case PRO_UI_DASHBOARD_HIDE:
		AfxMessageBox(_T("DashboardNotification_PRO_UI_DASHBOARD_HIDE"));
		break;
	case PRO_UI_DASHBOARD_SHOW:
		AfxMessageBox(_T("DashboardNotification_PRO_UI_DASHBOARD_SHOW"));
		break;
	case PRO_UI_DASHBOARD_DESTROY:
		AfxMessageBox(_T("DashboardNotification_PRO_UI_DASHBOARD_DESTROY"));
		break;
	case PRO_UI_DASHBOARD_DISMISS:
		AfxMessageBox(_T("DashboardNotification_PRO_UI_DASHBOARD_DISMISS"));
		break;
	case PRO_UI_DASHBOARD_EXIT:
		AfxMessageBox(_T("DashboardNotification_PRO_UI_DASHBOARD_EXIT"));
		break;
	case PRO_UI_DASHBOARD_ENTER:
		AfxMessageBox(_T("DashboardNotification_PRO_UI_DASHBOARD_ENTER"));
		break;
	default:
		break;
	}
	return PRO_TK_NO_ERROR;
}

void ShowDashBoard()
{
	ProError status;
	CleanOptions();
	status = DashboardMainPageSetup(NULL, &mainpage_options, "pagename", "mainpage");
	status = ProArrayAlloc(1, sizeof(ProUIDashboardPageOptions), 1, (ProArray *)&slideup_panels);
	status = DashboardSlidePageSetup(NULL, &slideup_panels[0]);
	status = ProUIDashboardshowoptionsAlloc(mainpage_options, slideup_panels, NULL, &dashboard_options);
	status = ProUIDashboardshowoptionsTitleSet(dashboard_options, _T("����dashboard"));
	status = ProUIDashboardshowoptionsNotificationSet(dashboard_options, (ProUIDashboardCallbackFunction)DashboardNotification, NULL);
	status = ProUIDashboardShow(dashboard_options);
}