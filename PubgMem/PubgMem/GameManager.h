#pragma once
#include "Process.h"
#include "PUBG_Engine_classes.h"
#include "Offsets.h"
#include <exception>
#include <future>
#include <atomic>
#include <mutex>
#include <list>
namespace PUBG
{
	extern HANDLE TragetHandle;
	class pubgCon
	{
	public:
		~pubgCon();
		static pubgCon *instance();

		VOID    MainLoop();
		VOID    InitObj();
		VOID    RefreshOffsets();

	public:
		UWorld          *pUWorld();
		ULevel          *pPlayList();
		ULocalPlayer    *pLocalPlayer();
		DWORD           GetPlayerCount();
		Vector3D		GetActorPos(DWORD_PTR pactor);
		std::string		GetActorNameById(int ID);
		const char*     GetActorName(PVOID pActor);
	private:
		Process           proc;
		HWND              GameWindow;  //.���ھ��
		NTSTATUS          status;
		std::atomic<bool> my_atomic;
		std::mutex        mymutex;

    /// ��Ϸ���
	private:
		DWORD_PTR     BaseAddress;
		UWorld        uWorld;
		ULocalPlayer  LocalPlayer;
	private:
		pubgCon();
		static pubgCon* m_instance;
	};
}