[+] Starting batch processing in directory: /home/mrnob0dy666/RUBBISH/BIG_EXE
    Output directory: /home/mrnob0dy666/RUBBISH/BIG_PURLOUT
    File pattern: default (*.exe,*.dll)
    Recursive: NO
[INFO] Entry point RVA: 0x5DC80
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x8F200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/loader_2.exe':
  - Section '.text': 586240 bytes at offset 0x600
[+] Success: Extracted 586240 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/loader_2.exe_shellcode.bin'
[INFO] SHA256: 40dc2b65e68224aa386de60f49319b3af176f1344f1ecc5ad50af473879660d8
[INFO] Entropy: 6.1748 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14D0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 10
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x2CA800
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/rustbuckit.exe':
  - Section '.text': 2926592 bytes at offset 0x400
[+] Success: Extracted 2926592 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/rustbuckit.exe_shellcode.bin'
[INFO] SHA256: 47622e95a89a2d5d3364748ff3713459bf6511e90b53d8e42a80ce34c512a3a2
[INFO] Entropy: 6.3155 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: advapi32.dll
    - Function: AdjustTokenPrivileges (Hint: 26)
    - Function: CryptAcquireContextW (Hint: 95)
    - Function: CryptDestroyKey (Hint: 101)
    - Function: CryptImportKey (Hint: 120)
    - Function: CryptReleaseContext (Hint: 121)
    - Function: LookupPrivilegeValueA (Hint: 202)
  Imported DLL: crypt32.dll
    - Function: CertAddCertificateContextToStore (Hint: 5)
    - Function: CertAddEncodedCTLToStore (Hint: 8)
    - Function: CertAddEncodedCertificateToStore (Hint: 9)
    - Function: CertCloseStore (Hint: 19)
    - Function: CertCreateCTLEntryFromCertificateContextProperties (Hint: 27)
    - Function: CertCreateCertificateContext (Hint: 29)
    - Function: CertDeleteCertificateFromStore (Hint: 34)
    - Function: CertDuplicateCertificateChain (Hint: 37)
    - Function: CertDuplicateCertificateContext (Hint: 38)
    - Function: CertDuplicateStore (Hint: 39)
    - Function: CertEnumCertificatesInStore (Hint: 45)
    - Function: CertFreeCTLContext (Hint: 61)
    - Function: CertFreeCertificateChain (Hint: 62)
    - Function: CertFreeCertificateContext (Hint: 65)
    - Function: CertGetCertificateChain (Hint: 70)
    - Function: CertGetCertificateContextProperty (Hint: 71)
    - Function: CertGetEnhancedKeyUsage (Hint: 72)
    - Function: CertOpenStore (Hint: 90)
    - Function: CertSetCertificateContextProperty (Hint: 109)
    - Function: CertVerifyCertificateChainPolicy (Hint: 119)
    - Function: CertVerifyTimeValidity (Hint: 122)
    - Function: CryptAcquireCertificatePrivateKey (Hint: 124)
    - Function: CryptBinaryToStringA (Hint: 125)
    - Function: CryptDecodeObjectEx (Hint: 132)
    - Function: CryptEncodeObjectEx (Hint: 136)
    - Function: CryptHashCertificate (Hint: 158)
    - Function: CryptMsgEncodeAndSignCTL (Hint: 179)
    - Function: CryptStringToBinaryA (Hint: 202)
    - Function: PFXExportCertStore (Hint: 219)
    - Function: PFXImportCertStore (Hint: 221)
  Imported DLL: kernel32.dll
    - Function: CancelIoEx (Hint: 21)
    - Function: CloseHandle (Hint: 27)
    - Function: ConnectNamedPipe (Hint: 29)
    - Function: CreateFileW (Hint: 53)
    - Function: CreateIoCompletionPort (Hint: 58)
    - Function: CreateNamedPipeW (Hint: 61)
    - Function: DisconnectNamedPipe (Hint: 79)
    - Function: GetLastError (Hint: 193)
    - Function: GetModuleHandleA (Hint: 207)
    - Function: GetModuleHandleW (Hint: 210)
    - Function: GetNamedPipeInfo (Hint: 217)
    - Function: GetOverlappedResult (Hint: 221)
    - Function: GetProcAddress (Hint: 234)
    - Function: GetQueuedCompletionStatusEx (Hint: 247)
    - Function: LocalFree (Hint: 353)
    - Function: PostQueuedCompletionStatus (Hint: 386)
    - Function: ReadFile (Hint: 400)
    - Function: SetFileCompletionNotificationModes (Hint: 437)
    - Function: SetHandleInformation (Hint: 451)
    - Function: VirtualAllocEx (Hint: 482)
    - Function: VirtualFreeEx (Hint: 485)
    - Function: VirtualQueryEx (Hint: 490)
    - Function: WriteFile (Hint: 497)
  Imported DLL: ncrypt.dll
    - Function: NCryptFreeObject (Hint: 17)
  Imported DLL: ntdll.dll
    - Function: NtCancelIoFileEx (Hint: 9)
    - Function: NtCreateFile (Hint: 13)
    - Function: NtDeviceIoControlFile (Hint: 18)
    - Function: RtlNtStatusToDosError (Hint: 157)
  Imported DLL: secur32.dll
    - Function: AcceptSecurityContext (Hint: 1)
    - Function: AcquireCredentialsHandleA (Hint: 2)
    - Function: ApplyControlToken (Hint: 8)
    - Function: DecryptMessage (Hint: 14)
    - Function: DeleteSecurityContext (Hint: 15)
    - Function: EncryptMessage (Hint: 18)
    - Function: FreeContextBuffer (Hint: 22)
    - Function: FreeCredentialsHandle (Hint: 23)
    - Function: InitializeSecurityContextW (Hint: 35)
    - Function: QueryContextAttributesW (Hint: 49)
  Imported DLL: ws2_32.dll
    - Function: WSADuplicateSocketW (Hint: 35)
    - Function: WSAGetLastError (Hint: 42)
    - Function: WSAIoctl (Hint: 53)
    - Function: WSAPoll (Hint: 60)
    - Function: WSARecv (Hint: 63)
    - Function: WSARecvFrom (Hint: 65)
    - Function: WSASend (Hint: 68)
    - Function: WSASendMsg (Hint: 70)
    - Function: WSASendTo (Hint: 71)
    - Function: WSASocketW (Hint: 76)
    - Function: accept (Hint: 112)
    - Function: bind (Hint: 113)
    - Function: closesocket (Hint: 114)
    - Function: connect (Hint: 115)
    - Function: getpeername (Hint: 122)
    - Function: getsockname (Hint: 127)
    - Function: getsockopt (Hint: 128)
    - Function: ioctlsocket (Hint: 135)
    - Function: listen (Hint: 136)
    - Function: recv (Hint: 139)
    - Function: recvfrom (Hint: 140)
    - Function: send (Hint: 142)
    - Function: sendto (Hint: 143)
    - Function: setsockopt (Hint: 144)
    - Function: shutdown (Hint: 145)
    - Function: socket (Hint: 146)
  Imported DLL: KERNEL32.dll
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: RaiseException (Hint: 1153)
    - Function: RtlUnwindEx (Hint: 1236)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: __C_specific_handler (Hint: 1584)
  Imported DLL: msvcrt.dll
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _fpreset (Hint: 223)
    - Function: _initterm (Hint: 283)
    - Function: _onexit (Hint: 551)
    - Function: abort (Hint: 901)
    - Function: calloc (Hint: 918)
    - Function: exit (Hint: 931)
    - Function: fprintf (Hint: 951)
    - Function: free (Hint: 958)
    - Function: fwrite (Hint: 971)
    - Function: malloc (Hint: 1018)
    - Function: memcmp (Hint: 1025)
    - Function: memcpy (Hint: 1026)
    - Function: memmove (Hint: 1027)
    - Function: memset (Hint: 1028)
    - Function: signal (Hint: 1058)
    - Function: strlen (Hint: 1081)
    - Function: strncmp (Hint: 1084)
    - Function: vfprintf (Hint: 1118)
  Imported DLL: ntdll.dll
    - Function: NtCreateNamedPipeFile (Hint: 330)
  Imported DLL: advapi32.dll
    - Function: ControlService (Hint: 0)
    - Function: OpenProcessToken (Hint: 0)
    - Function: OpenSCManagerW (Hint: 0)
    - Function: OpenServiceW (Hint: 0)
    - Function: RegCloseKey (Hint: 0)
    - Function: RegEnumKeyExW (Hint: 0)
    - Function: RegEnumValueW (Hint: 0)
    - Function: RegOpenKeyExA (Hint: 0)
    - Function: RegOpenKeyExW (Hint: 0)
    - Function: RegQueryInfoKeyW (Hint: 0)
    - Function: RegQueryValueExW (Hint: 0)
    - Function: RegSetValueExA (Hint: 0)
    - Function: SystemFunction036 (Hint: 0)
  Imported DLL: bcrypt.dll
    - Function: BCryptGenRandom (Hint: 0)
  Imported DLL: kernel32.dll
    - Function: AddVectoredExceptionHandler (Hint: 0)
    - Function: CancelIo (Hint: 0)
    - Function: CompareStringOrdinal (Hint: 0)
    - Function: CopyFileExW (Hint: 0)
    - Function: CreateDirectoryW (Hint: 0)
    - Function: CreateEventW (Hint: 0)
    - Function: CreateFileMappingA (Hint: 0)
    - Function: CreateHardLinkW (Hint: 0)
    - Function: CreatePipe (Hint: 0)
    - Function: CreateProcessW (Hint: 0)
    - Function: CreateRemoteThread (Hint: 0)
    - Function: CreateSymbolicLinkW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateToolhelp32Snapshot (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: DeleteFileW (Hint: 0)
    - Function: DeleteProcThreadAttributeList (Hint: 0)
    - Function: DeviceIoControl (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: FileTimeToSystemTime (Hint: 0)
    - Function: FindClose (Hint: 0)
    - Function: FindFirstFileExW (Hint: 0)
    - Function: FindNextFileW (Hint: 0)
    - Function: FlushFileBuffers (Hint: 0)
    - Function: FormatMessageW (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: GetCommandLineW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: GetConsoleOutputCP (Hint: 0)
    - Function: GetCurrentDirectoryW (Hint: 0)
    - Function: GetCurrentProcess (Hint: 0)
    - Function: GetCurrentProcessId (Hint: 0)
    - Function: GetCurrentThread (Hint: 0)
    - Function: GetCurrentThreadId (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetEnvironmentVariableW (Hint: 0)
    - Function: GetExitCodeProcess (Hint: 0)
    - Function: GetFileAttributesW (Hint: 0)
    - Function: GetFileInformationByHandle (Hint: 0)
    - Function: GetFileInformationByHandleEx (Hint: 0)
    - Function: GetFileSizeEx (Hint: 0)
    - Function: GetFileType (Hint: 0)
    - Function: GetFinalPathNameByHandleW (Hint: 0)
    - Function: GetFullPathNameW (Hint: 0)
    - Function: GetModuleFileNameW (Hint: 0)
    - Function: GetProcessHeap (Hint: 0)
    - Function: GetProcessId (Hint: 0)
    - Function: GetStartupInfoA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetSystemDirectoryW (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemTimePreciseAsFileTime (Hint: 0)
    - Function: GetTempPathW (Hint: 0)
    - Function: GetWindowsDirectoryW (Hint: 0)
    - Function: HeapAlloc (Hint: 0)
    - Function: HeapFree (Hint: 0)
    - Function: HeapReAlloc (Hint: 0)
    - Function: InitOnceBeginInitialize (Hint: 0)
    - Function: InitOnceComplete (Hint: 0)
    - Function: InitializeProcThreadAttributeList (Hint: 0)
    - Function: IsDebuggerPresent (Hint: 0)
    - Function: LockFileEx (Hint: 0)
    - Function: MapViewOfFile (Hint: 0)
    - Function: Module32FirstW (Hint: 0)
    - Function: Module32NextW (Hint: 0)
    - Function: MoveFileExW (Hint: 0)
    - Function: MultiByteToWideChar (Hint: 0)
    - Function: OpenProcess (Hint: 0)
    - Function: Process32First (Hint: 0)
    - Function: Process32Next (Hint: 0)
    - Function: QueryPerformanceCounter (Hint: 0)
    - Function: QueryPerformanceFrequency (Hint: 0)
    - Function: ReadConsoleW (Hint: 0)
    - Function: ReadFileEx (Hint: 0)
    - Function: RemoveDirectoryW (Hint: 0)
    - Function: RtlCaptureContext (Hint: 0)
    - Function: RtlLookupFunctionEntry (Hint: 0)
    - Function: RtlVirtualUnwind (Hint: 0)
    - Function: SetCurrentDirectoryW (Hint: 0)
    - Function: SetEnvironmentVariableW (Hint: 0)
    - Function: SetFileAttributesW (Hint: 0)
    - Function: SetFileInformationByHandle (Hint: 0)
    - Function: SetFilePointerEx (Hint: 0)
    - Function: SetFileTime (Hint: 0)
    - Function: SetLastError (Hint: 0)
    - Function: SetThreadStackGuarantee (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: Sleep (Hint: 0)
    - Function: SleepEx (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: TerminateProcess (Hint: 0)
    - Function: TlsAlloc (Hint: 0)
    - Function: TlsFree (Hint: 0)
    - Function: TlsGetValue (Hint: 0)
    - Function: TlsSetValue (Hint: 0)
    - Function: UnlockFile (Hint: 0)
    - Function: UnmapViewOfFile (Hint: 0)
    - Function: UpdateProcThreadAttribute (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: WideCharToMultiByte (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WriteFileEx (Hint: 0)
    - Function: WriteProcessMemory (Hint: 0)
  Imported DLL: ntdll.dll
    - Function: NtOpenFile (Hint: 0)
    - Function: NtReadFile (Hint: 0)
    - Function: NtWriteFile (Hint: 0)
  Imported DLL: psapi.dll
    - Function: GetProcessMemoryInfo (Hint: 0)
  Imported DLL: user32.dll
    - Function: CallNextHookEx (Hint: 0)
    - Function: GetKeyboardState (Hint: 0)
    - Function: SetWindowsHookExA (Hint: 0)
    - Function: ToUnicode (Hint: 0)
    - Function: UnhookWindowsHookEx (Hint: 0)
  Imported DLL: userenv.dll
    - Function: GetUserProfileDirectoryW (Hint: 0)
  Imported DLL: ws2_32.dll
    - Function: WSACleanup (Hint: 0)
    - Function: WSAStartup (Hint: 0)
    - Function: freeaddrinfo (Hint: 0)
    - Function: getaddrinfo (Hint: 0)
    - Function: select (Hint: 0)
  Imported DLL: api-ms-win-core-synch-l1-2-0.dll
    - Function: WaitOnAddress (Hint: 3)
    - Function: WakeByAddressAll (Hint: 1)
    - Function: WakeByAddressSingle (Hint: 2)
  Imported DLL: bcryptprimitives.dll
    - Function: ProcessPrng (Hint: 1)
[END IMPORTS ANALYSIS - 20 DLLs imported]

[INFO] Entry point RVA: 0x4E8490
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 3
[INFO] Input file is an executable.
[DEBUG] Processing section 'UPX1': RVA=0x30F000, Raw=0x200, Size=0x1D9800
[INFO] Entry point is in section 'UPX1'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/cshost.exe':
  - Section 'UPX1': 1939456 bytes at offset 0x200
[+] Success: Extracted 1939456 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/cshost.exe_shellcode.bin'
[INFO] SHA256: 11b59d4dce0cc77910d2307f478fbc50a6167c3250cbd12434ecd950b0db1b18
[INFO] Entropy: 7.8933 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: KERNEL32.DLL
    - Function: LoadLibraryA (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: VirtualProtect (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 5
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0xA00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/wingaypi.exe':
  - Section '.text': 2560 bytes at offset 0x400
[+] Success: Extracted 2560 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/wingaypi.exe_shellcode.bin'
[INFO] SHA256: f25884a93357dbba045e2cd8792db847e138d2502a72695aa9a512aeae44f6e7
[INFO] Entropy: 4.1531 bits/byte

[IMPORTS ANALYSIS]
[END IMPORTS ANALYSIS - 0 DLLs imported]

[INFO] Entry point RVA: 0x63AC0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x220200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/rocksolid.exe':
  - Section '.text': 2228736 bytes at offset 0x600
[+] Success: Extracted 2228736 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/rocksolid.exe_shellcode.bin'
[INFO] SHA256: 808ae9304f7f53121b5c1b29e48200619bbda36fba92ba08c3eeef5c9384c0e9
[INFO] Entropy: 6.1531 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x86 (32-bit)
[INFO] Number of sections: 4
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/c_B_f.exe':
  - Section '.text': 1024 bytes at offset 0x400
[+] Success: Extracted 1024 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/c_B_f.exe_shellcode.bin'
[INFO] SHA256: 616033fee0e1ef1665234b279aceaec06a04fd6b47e8088b96b18bb7d36bde7e
[INFO] Entropy: 3.7870 bits/byte

[IMPORTS ANALYSIS]
[END IMPORTS ANALYSIS - 0 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x1A00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/klogging.exe':
  - Section '.text': 6656 bytes at offset 0x600
[+] Success: Extracted 6656 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/klogging.exe_shellcode.bin'
[INFO] SHA256: 2fe5d1449064dcbed010243f0f681677d330d13cbb0bc3850dbdb895916f9cb9
[INFO] Entropy: 5.8675 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: KERNEL32.dll
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetConsoleWindow (Hint: 536)
    - Function: GetLastError (Hint: 630)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: signal (Hint: 1063)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: vfprintf (Hint: 1123)
  Imported DLL: USER32.dll
    - Function: ShowWindow (Hint: 865)
[END IMPORTS ANALYSIS - 3 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0xB0200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/IG_strike.exe':
  - Section '.text': 721408 bytes at offset 0x600
[+] Success: Extracted 721408 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/IG_strike.exe_shellcode.bin'
[INFO] SHA256: a194d776ba3b772b9651f16260fc59514ed40237e9b62d1da7156ef57ac42355
[INFO] Entropy: 6.1420 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CreateSemaphoreW (Hint: 246)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetCurrentThreadId (Hint: 557)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleHandleW (Hint: 654)
    - Function: GetProcAddress (Hint: 710)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDBCSLeadByteEx (Hint: 919)
    - Function: IsDebuggerPresent (Hint: 920)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: LoadLibraryW (Hint: 991)
    - Function: MultiByteToWideChar (Hint: 1036)
    - Function: RaiseException (Hint: 1153)
    - Function: ReleaseSemaphore (Hint: 1196)
    - Function: RtlCaptureContext (Hint: 1223)
    - Function: RtlLookupFunctionEntry (Hint: 1230)
    - Function: RtlUnwindEx (Hint: 1236)
    - Function: RtlVirtualUnwind (Hint: 1237)
    - Function: SetLastError (Hint: 1334)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsAlloc (Hint: 1443)
    - Function: TlsFree (Hint: 1444)
    - Function: TlsGetValue (Hint: 1445)
    - Function: TlsSetValue (Hint: 1446)
    - Function: VirtualAlloc (Hint: 1486)
    - Function: VirtualFree (Hint: 1489)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForSingleObject (Hint: 1503)
    - Function: WideCharToMultiByte (Hint: 1547)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: ___lc_codepage_func (Hint: 64)
    - Function: ___mb_cur_max_func (Hint: 67)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _errno (Hint: 190)
    - Function: _filelengthi64 (Hint: 210)
    - Function: _fileno (Hint: 211)
    - Function: _fmode (Hint: 220)
    - Function: _fstat64 (Hint: 234)
    - Function: _initterm (Hint: 285)
    - Function: _lseeki64 (Hint: 396)
    - Function: _onexit (Hint: 553)
    - Function: _strnicmp (Hint: 658)
    - Function: _wfopen (Hint: 832)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fclose (Hint: 940)
    - Function: fflush (Hint: 943)
    - Function: fgetpos (Hint: 945)
    - Function: fopen (Hint: 953)
    - Function: fprintf (Hint: 956)
    - Function: fputc (Hint: 958)
    - Function: fputs (Hint: 959)
    - Function: fread (Hint: 962)
    - Function: free (Hint: 963)
    - Function: fsetpos (Hint: 971)
    - Function: fwrite (Hint: 976)
    - Function: getc (Hint: 980)
    - Function: getwc (Hint: 985)
    - Function: isspace (Hint: 998)
    - Function: iswctype (Hint: 1004)
    - Function: localeconv (Hint: 1017)
    - Function: malloc (Hint: 1023)
    - Function: memchr (Hint: 1029)
    - Function: memcmp (Hint: 1030)
    - Function: memcpy (Hint: 1031)
    - Function: memmove (Hint: 1032)
    - Function: memset (Hint: 1033)
    - Function: putc (Hint: 1043)
    - Function: putwc (Hint: 1046)
    - Function: realloc (Hint: 1052)
    - Function: setlocale (Hint: 1061)
    - Function: setvbuf (Hint: 1062)
    - Function: signal (Hint: 1063)
    - Function: strcmp (Hint: 1079)
    - Function: strcoll (Hint: 1080)
    - Function: strerror (Hint: 1084)
    - Function: strftime (Hint: 1085)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strxfrm (Hint: 1101)
    - Function: towlower (Hint: 1118)
    - Function: towupper (Hint: 1119)
    - Function: ungetc (Hint: 1120)
    - Function: ungetwc (Hint: 1121)
    - Function: vfprintf (Hint: 1123)
    - Function: wcscoll (Hint: 1144)
    - Function: wcsftime (Hint: 1148)
    - Function: wcslen (Hint: 1149)
    - Function: wcsxfrm (Hint: 1168)
    - Function: _write (Hint: 1212)
    - Function: _read (Hint: 1254)
    - Function: _fileno (Hint: 1281)
    - Function: _fdopen (Hint: 1285)
    - Function: _close (Hint: 1301)
  Imported DLL: USER32.dll
    - Function: FindWindowW (Hint: 273)
[END IMPORTS ANALYSIS - 3 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 20
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x1A0800
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/vmescape.exe':
  - Section '.text': 1705984 bytes at offset 0x600
[+] Success: Extracted 1705984 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/vmescape.exe_shellcode.bin'
[INFO] SHA256: 4b9b2b49744de18ec0c6bdd4320abd030cee09175ec2b22e1ce797e7dfd06a61
[INFO] Entropy: 6.1852 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExA (Hint: 1652)
    - Function: RegQueryValueExA (Hint: 1665)
  Imported DLL: KERNEL32.dll
    - Function: AddVectoredExceptionHandler (Hint: 20)
    - Function: CloseHandle (Hint: 141)
    - Function: CreateEventA (Hint: 197)
    - Function: CreateFileA (Hint: 204)
    - Function: CreateIoCompletionPort (Hint: 217)
    - Function: CreateThread (Hint: 252)
    - Function: CreateWaitableTimerExW (Hint: 266)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: DuplicateHandle (Hint: 313)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: ExitProcess (Hint: 366)
    - Function: FreeEnvironmentStringsW (Hint: 442)
    - Function: GetConsoleMode (Hint: 525)
    - Function: GetEnvironmentStringsW (Hint: 587)
    - Function: GetLastError (Hint: 630)
    - Function: GetProcAddress (Hint: 710)
    - Function: GetProcessAffinityMask (Hint: 711)
    - Function: GetQueuedCompletionStatusEx (Hint: 739)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: GetStdHandle (Hint: 746)
    - Function: GetSystemDirectoryA (Hint: 759)
    - Function: GetSystemInfo (Hint: 763)
    - Function: GetThreadContext (Hint: 783)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDBCSLeadByteEx (Hint: 919)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: LoadLibraryA (Hint: 988)
    - Function: LoadLibraryW (Hint: 991)
    - Function: MultiByteToWideChar (Hint: 1036)
    - Function: PostQueuedCompletionStatus (Hint: 1089)
    - Function: ResumeThread (Hint: 1221)
    - Function: SetConsoleCtrlHandler (Hint: 1261)
    - Function: SetErrorMode (Hint: 1305)
    - Function: SetEvent (Hint: 1306)
    - Function: SetProcessPriorityBoost (Hint: 1352)
    - Function: SetThreadContext (Hint: 1368)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: SetWaitableTimer (Hint: 1403)
    - Function: Sleep (Hint: 1410)
    - Function: SuspendThread (Hint: 1418)
    - Function: SwitchToThread (Hint: 1420)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualAlloc (Hint: 1486)
    - Function: VirtualFree (Hint: 1489)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForMultipleObjects (Hint: 1501)
    - Function: WaitForSingleObject (Hint: 1503)
    - Function: WideCharToMultiByte (Hint: 1547)
    - Function: WriteConsoleW (Hint: 1566)
    - Function: WriteFile (Hint: 1567)
    - Function: __C_specific_handler (Hint: 1584)
  Imported DLL: msvcrt.dll
    - Function: ___lc_codepage_func (Hint: 64)
    - Function: ___mb_cur_max_func (Hint: 67)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _beginthread (Hint: 134)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _errno (Hint: 190)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _lock (Hint: 387)
    - Function: _onexit (Hint: 553)
    - Function: _unlock (Hint: 714)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: fputc (Hint: 958)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: localeconv (Hint: 1017)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: signal (Hint: 1063)
    - Function: strerror (Hint: 1084)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: vfprintf (Hint: 1123)
    - Function: wcslen (Hint: 1149)
[END IMPORTS ANALYSIS - 3 DLLs imported]
[EXPORTS ANALYSIS - a.out.exe]
  Base Ordinal: 1
  Number of Functions: 1
  Number of Names: 1
    - Function: _cgo_dummy_export
[END EXPORTS ANALYSIS]
[INFO] Entry point RVA: 0x14C0
[INFO] Machine type: x86 (32-bit)
[INFO] Number of sections: 17
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/monogogo_win_exploit_no_debug.exe':
  - Section '.text': 9216 bytes at offset 0x600
[+] Success: Extracted 9216 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/monogogo_win_exploit_no_debug.exe_shellcode.bin'
[INFO] SHA256: d3a3cfe27fd1f710cd1f6af33a0e53ae437bb3630fae582d5a8322fae7b88bfe
[INFO] Entropy: 5.6184 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: CloseServiceHandle (Hint: 1088)
    - Function: OpenSCManagerA (Hint: 1512)
    - Function: OpenServiceA (Hint: 1514)
    - Function: RegCloseKey (Hint: 1569)
    - Function: RegOpenKeyExA (Hint: 1617)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 136)
    - Function: CreateFileA (Hint: 199)
    - Function: CreateThread (Hint: 247)
    - Function: DeleteCriticalSection (Hint: 277)
    - Function: DeleteFileA (Hint: 279)
    - Function: EnterCriticalSection (Hint: 310)
    - Function: FreeLibrary (Hint: 433)
    - Function: GetEnvironmentVariableA (Hint: 576)
    - Function: GetFileAttributesA (Hint: 584)
    - Function: GetLastError (Hint: 617)
    - Function: GetModuleHandleA (Hint: 637)
    - Function: GetProcAddress (Hint: 694)
    - Function: GetStartupInfoA (Hint: 729)
    - Function: InitializeCriticalSection (Hint: 877)
    - Function: LeaveCriticalSection (Hint: 973)
    - Function: LoadLibraryA (Hint: 977)
    - Function: SetUnhandledExceptionFilter (Hint: 1370)
    - Function: Sleep (Hint: 1386)
    - Function: TlsGetValue (Hint: 1421)
    - Function: VirtualProtect (Hint: 1469)
    - Function: VirtualQuery (Hint: 1472)
    - Function: WaitForMultipleObjects (Hint: 1479)
  Imported DLL: msvcrt.dll
    - Function: __getmainargs (Hint: 58)
    - Function: __initenv (Hint: 59)
    - Function: __lconv_init (Hint: 68)
    - Function: __p__acmdln (Hint: 76)
    - Function: __p__commode (Hint: 78)
    - Function: __p__fmode (Hint: 83)
    - Function: __set_app_type (Hint: 104)
    - Function: __setusermatherr (Hint: 107)
    - Function: _amsg_exit (Hint: 142)
    - Function: _cexit (Hint: 159)
    - Function: _initterm (Hint: 338)
    - Function: _iob (Hint: 342)
    - Function: _onexit (Hint: 570)
    - Function: abort (Hint: 922)
    - Function: calloc (Hint: 935)
    - Function: exit (Hint: 945)
    - Function: fprintf (Hint: 962)
    - Function: free (Hint: 969)
    - Function: fwrite (Hint: 982)
    - Function: malloc (Hint: 1027)
    - Function: memcpy (Hint: 1035)
    - Function: signal (Hint: 1064)
    - Function: srand (Hint: 1070)
    - Function: strlen (Hint: 1084)
    - Function: strncmp (Hint: 1087)
    - Function: vfprintf (Hint: 1121)
    - Function: time (Hint: 713)
  Imported DLL: SETUPAPI.dll
    - Function: SetupDiDestroyDeviceInfoList (Hint: 320)
    - Function: SetupDiGetClassDevsA (Hint: 340)
  Imported DLL: WS2_32.dll
    - Function: WSACleanup (Hint: 27)
    - Function: WSAStartup (Hint: 85)
    - Function: closesocket (Hint: 135)
    - Function: socket (Hint: 167)
[END IMPORTS ANALYSIS - 5 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/goofygoober_1.exe':
  - Section '.text': 8704 bytes at offset 0x600
[+] Success: Extracted 8704 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/goofygoober_1.exe_shellcode.bin'
[INFO] SHA256: aef1fed4b9dc19b8f57b8a5514f7d90e61a7b43d1918736223ccbb0379186fd8
[INFO] Entropy: 5.8167 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: CloseServiceHandle (Hint: 1102)
    - Function: CreateServiceA (Hint: 1144)
    - Function: OpenSCManagerA (Hint: 1535)
  Imported DLL: KERNEL32.dll
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: ExitProcess (Hint: 366)
    - Function: GetCurrentProcess (Hint: 552)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleHandleA (Hint: 651)
    - Function: GetProcAddress (Hint: 710)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: GetSystemTimeAsFileTime (Hint: 769)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: OpenProcess (Hint: 1069)
    - Function: QueryFullProcessImageNameA (Hint: 1124)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualAlloc (Hint: 1486)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WriteProcessMemory (Hint: 1576)
    - Function: __C_specific_handler (Hint: 1584)
  Imported DLL: msvcrt.dll
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: _snprintf (Hint: 605)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: memset (Hint: 1033)
    - Function: signal (Hint: 1063)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strstr (Hint: 1095)
    - Function: vfprintf (Hint: 1123)
  Imported DLL: USER32.dll
    - Function: CallNextHookEx (Hint: 31)
    - Function: GetKeyboardState (Hint: 357)
    - Function: SetWindowsHookExA (Hint: 856)
    - Function: ToAscii (Hint: 886)
  Imported DLL: WINHTTP.dll
    - Function: WinHttpCloseHandle (Hint: 9)
    - Function: WinHttpConnect (Hint: 10)
    - Function: WinHttpOpen (Hint: 39)
    - Function: WinHttpOpenRequest (Hint: 40)
    - Function: WinHttpReceiveResponse (Hint: 63)
    - Function: WinHttpSendRequest (Hint: 66)
[END IMPORTS ANALYSIS - 5 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 4
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x600
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/stairslide.exe':
  - Section '.text': 1536 bytes at offset 0x400
[+] Success: Extracted 1536 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/stairslide.exe_shellcode.bin'
[INFO] SHA256: b56fb4c55845edb689dd20300df5c9be73029b0def939798fc6c9412b0dbf2d4
[INFO] Entropy: 4.3915 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: CloseServiceHandle (Hint: 1102)
    - Function: ControlService (Hint: 1107)
    - Function: OpenSCManagerA (Hint: 1535)
    - Function: OpenServiceA (Hint: 1537)
  Imported DLL: KERNEL32.dll
    - Function: CreateProcessA (Hint: 234)
    - Function: ExitProcess (Hint: 366)
    - Function: GetModuleHandleA (Hint: 651)
    - Function: GetSystemDefaultLangID (Hint: 756)
    - Function: HeapAlloc (Hint: 863)
    - Function: HeapCreate (Hint: 865)
    - Function: HeapFree (Hint: 869)
    - Function: lstrlenA (Hint: 1611)
  Imported DLL: USER32.dll
    - Function: CallNextHookEx (Hint: 31)
    - Function: DispatchMessageA (Hint: 185)
    - Function: GetMessageA (Hint: 380)
    - Function: SetWindowsHookExA (Hint: 856)
    - Function: TranslateMessage (Hint: 897)
    - Function: UnhookWindowsHookEx (Hint: 901)
    - Function: wsprintfA (Hint: 958)
  Imported DLL: WS2_32.dll
    - Function: WSACleanup (Hint: 31)
    - Function: WSAStartup (Hint: 89)
    - Function: closesocket (Hint: 164)
    - Function: connect (Hint: 165)
    - Function: send (Hint: 192)
    - Function: socket (Hint: 196)
[END IMPORTS ANALYSIS - 4 DLLs imported]

[INFO] Entry point RVA: 0x75720
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 15
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x123A00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/shaky.exe':
  - Section '.text': 1194496 bytes at offset 0x600
[+] Success: Extracted 1194496 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/shaky.exe_shellcode.bin'
[INFO] SHA256: 72eeb8d076706968bcc7a072fee513f2399d2a49e3fa657636797b00cc056d81
[INFO] Entropy: 6.2909 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WerSetFlags (Hint: 0)
    - Function: WerGetFlags (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: TlsAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: RtlVirtualUnwind (Hint: 0)
    - Function: RtlLookupFunctionEntry (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: RaiseFailFastException (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: LoadLibraryExW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetErrorMode (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetCurrentThreadId (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
    - Function: AddVectoredContinueHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x5E580
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0xAB400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/quicky2.exe':
  - Section '.text': 701440 bytes at offset 0x600
[+] Success: Extracted 701440 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/quicky2.exe_shellcode.bin'
[INFO] SHA256: f7a4aa42bc8d07038d8da9ab5e22def6dd0512102093c3411b4b8cbb7f4ce685
[INFO] Entropy: 6.1826 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x1A00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/modified_klogging.exe':
  - Section '.text': 6656 bytes at offset 0x600
[+] Success: Extracted 6656 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/modified_klogging.exe_shellcode.bin'
[INFO] SHA256: 2fe5d1449064dcbed010243f0f681677d330d13cbb0bc3850dbdb895916f9cb9
[INFO] Entropy: 5.8675 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: KERNEL32.dll
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetConsoleWindow (Hint: 536)
    - Function: GetLastError (Hint: 630)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: signal (Hint: 1063)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: vfprintf (Hint: 1123)
  Imported DLL: USER32.dll
    - Function: ShowWindow (Hint: 865)
[END IMPORTS ANALYSIS - 3 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 3
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/NyXyS.exe':
  - Section '.text': 512 bytes at offset 0x400
[+] Success: Extracted 512 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/NyXyS.exe_shellcode.bin'
[INFO] SHA256: 2761d3fe408e8a7ad7f4e0b67ba772163c62ec6be8f4ec6b2cf37efc7a38e451
[INFO] Entropy: 0.2006 bits/byte

[IMPORTS ANALYSIS]
[END IMPORTS ANALYSIS - 0 DLLs imported]

[INFO] Entry point RVA: 0x777A0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 15
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2BB400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/uhmento_buttered.exe':
  - Section '.text': 2864128 bytes at offset 0x600
[+] Success: Extracted 2864128 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/uhmento_buttered.exe_shellcode.bin'
[INFO] SHA256: 4e02b5041103c33b15afba3f5302411a7d2a76faa07ce92168959db43b916ab2
[INFO] Entropy: 6.2092 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WerSetFlags (Hint: 0)
    - Function: WerGetFlags (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: TlsAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: RtlVirtualUnwind (Hint: 0)
    - Function: RtlLookupFunctionEntry (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: RaiseFailFastException (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: LoadLibraryExW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetErrorMode (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetCurrentThreadId (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
    - Function: AddVectoredContinueHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x4200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/installer_2.exe':
  - Section '.text': 16896 bytes at offset 0x600
[+] Success: Extracted 16896 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/installer_2.exe_shellcode.bin'
[INFO] SHA256: ff5e04ed8f48b6f99f7bf7a16c28521a57a076d0995498142f90f4593a2ae9ce
[INFO] Entropy: 5.6976 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: CryptAcquireContextA (Hint: 1194)
    - Function: CryptCreateHash (Hint: 1197)
    - Function: CryptDecrypt (Hint: 1198)
    - Function: CryptDeriveKey (Hint: 1199)
    - Function: CryptDestroyHash (Hint: 1200)
    - Function: CryptDestroyKey (Hint: 1201)
    - Function: CryptGenRandom (Hint: 1211)
    - Function: CryptHashData (Hint: 1218)
    - Function: CryptReleaseContext (Hint: 1221)
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExA (Hint: 1652)
    - Function: RegQueryValueExA (Hint: 1665)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CreateThread (Hint: 252)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: ExitProcess (Hint: 366)
    - Function: GetLastError (Hint: 630)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDebuggerPresent (Hint: 920)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualAlloc (Hint: 1486)
    - Function: VirtualFree (Hint: 1489)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForSingleObject (Hint: 1503)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: _time64 (Hint: 693)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: memmove (Hint: 1032)
    - Function: rand (Hint: 1051)
    - Function: signal (Hint: 1063)
    - Function: srand (Hint: 1072)
    - Function: strcat_s (Hint: 1077)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strstr (Hint: 1095)
    - Function: vfprintf (Hint: 1123)
  Imported DLL: WININET.dll
    - Function: InternetCloseHandle (Hint: 145)
    - Function: InternetOpenA (Hint: 194)
    - Function: InternetOpenUrlA (Hint: 195)
    - Function: InternetReadFile (Hint: 202)
  Imported DLL: libgcc_s_seh-1.dll
    - Function: _Unwind_Resume (Hint: 15)
  Imported DLL: libstdc++-6.dll
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv (Hint: 731)
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv (Hint: 743)
    - Function: _ZNSaIcEC1Ev (Hint: 1265)
    - Function: _ZNSaIcED1Ev (Hint: 1268)
    - Function: _ZNSaIcED2Ev (Hint: 1269)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv (Hint: 3670)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEy (Hint: 3673)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcRKS3_ (Hint: 3675)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv (Hint: 3685)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEy (Hint: 3686)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsEPcPKcS7_ (Hint: 3689)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendEPKc (Hint: 3711)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc (Hint: 3739)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERyy (Hint: 3769)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_ (Hint: 3775)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev (Hint: 3808)
    - Function: _ZSt17__throw_bad_allocv (Hint: 4624)
    - Function: _ZSt19__throw_logic_errorPKc (Hint: 4638)
    - Function: _ZSt20__throw_length_errorPKc (Hint: 4646)
    - Function: _ZdaPv (Hint: 5611)
    - Function: _ZdlPvy (Hint: 5621)
    - Function: _Znay (Hint: 5623)
    - Function: _Znwy (Hint: 5627)
    - Function: __cxa_begin_catch (Hint: 5637)
    - Function: __cxa_end_catch (Hint: 5642)
    - Function: __cxa_rethrow (Hint: 5653)
    - Function: __gxx_personality_seh0 (Hint: 5670)
[END IMPORTS ANALYSIS - 6 DLLs imported]

[INFO] Entry point RVA: 0x3AEE
[INFO] Machine type: x86 (32-bit)
[INFO] Number of sections: 4
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x2000, Raw=0x400, Size=0x1C00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/module_3.exe':
  - Section '.text': 7168 bytes at offset 0x400
[+] Success: Extracted 7168 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/module_3.exe_shellcode.bin'
[INFO] SHA256: 4a6b94274f550f4cf7ebdaf6a754abea5a4113bc21dd3065cf71d7e13e027f07
[INFO] Entropy: 5.3734 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: mscoree.dll
    - Function: _CorExeMain (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x319E
[INFO] Machine type: x86 (32-bit)
[INFO] Number of sections: 3
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x2000, Raw=0x200, Size=0x1200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/module_1.exe':
  - Section '.text': 4608 bytes at offset 0x200
[+] Success: Extracted 4608 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/module_1.exe_shellcode.bin'
[INFO] SHA256: a0458fa886496757d2c692b2e397cfd313b1c67662999780e9d3c144a273099e
[INFO] Entropy: 5.1814 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: mscoree.dll
    - Function: _CorExeMain (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x637C0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x224400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/inmem.exe':
  - Section '.text': 2245632 bytes at offset 0x600
[+] Success: Extracted 2245632 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/inmem.exe_shellcode.bin'
[INFO] SHA256: d12da98a419e70ab90a9db18746b7977af611e4285a6ec62e200bd203b2e75e2
[INFO] Entropy: 6.1616 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 5
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x600
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/panyx.exe':
  - Section '.text': 1536 bytes at offset 0x400
[+] Success: Extracted 1536 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/panyx.exe_shellcode.bin'
[INFO] SHA256: 1b4fd71a1058c60ef72e5d2e22f8323fd11a2790cba6b70073a2a87a1def8b4f
[INFO] Entropy: 5.6372 bits/byte

[IMPORTS ANALYSIS]
[END IMPORTS ANALYSIS - 0 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/goofygoober.exe':
  - Section '.text': 8704 bytes at offset 0x600
[+] Success: Extracted 8704 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/goofygoober.exe_shellcode.bin'
[INFO] SHA256: aef1fed4b9dc19b8f57b8a5514f7d90e61a7b43d1918736223ccbb0379186fd8
[INFO] Entropy: 5.8167 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: CloseServiceHandle (Hint: 1102)
    - Function: CreateServiceA (Hint: 1144)
    - Function: OpenSCManagerA (Hint: 1535)
  Imported DLL: KERNEL32.dll
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: ExitProcess (Hint: 366)
    - Function: GetCurrentProcess (Hint: 552)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleHandleA (Hint: 651)
    - Function: GetProcAddress (Hint: 710)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: GetSystemTimeAsFileTime (Hint: 769)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: OpenProcess (Hint: 1069)
    - Function: QueryFullProcessImageNameA (Hint: 1124)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualAlloc (Hint: 1486)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WriteProcessMemory (Hint: 1576)
    - Function: __C_specific_handler (Hint: 1584)
  Imported DLL: msvcrt.dll
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: _snprintf (Hint: 605)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: memset (Hint: 1033)
    - Function: signal (Hint: 1063)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strstr (Hint: 1095)
    - Function: vfprintf (Hint: 1123)
  Imported DLL: USER32.dll
    - Function: CallNextHookEx (Hint: 31)
    - Function: GetKeyboardState (Hint: 357)
    - Function: SetWindowsHookExA (Hint: 856)
    - Function: ToAscii (Hint: 886)
  Imported DLL: WINHTTP.dll
    - Function: WinHttpCloseHandle (Hint: 9)
    - Function: WinHttpConnect (Hint: 10)
    - Function: WinHttpOpen (Hint: 39)
    - Function: WinHttpOpenRequest (Hint: 40)
    - Function: WinHttpReceiveResponse (Hint: 63)
    - Function: WinHttpSendRequest (Hint: 66)
[END IMPORTS ANALYSIS - 5 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x1A00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/nyxnyx.exe':
  - Section '.text': 6656 bytes at offset 0x600
[+] Success: Extracted 6656 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/nyxnyx.exe_shellcode.bin'
[INFO] SHA256: 32da9ba14cf4563816dc6567ee6a7b7ddcd2947efdaf8ccc664414ddc2929436
[INFO] Entropy: 5.9415 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: KERNEL32.dll
    - Function: CreateProcessA (Hint: 234)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetLastError (Hint: 630)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _fpreset (Hint: 223)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: memset (Hint: 1033)
    - Function: signal (Hint: 1063)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: vfprintf (Hint: 1123)
  Imported DLL: WS2_32.dll
    - Function: WSAConnect (Hint: 33)
    - Function: WSASocketA (Hint: 87)
    - Function: WSAStartup (Hint: 89)
    - Function: htons (Hint: 180)
    - Function: inet_addr (Hint: 181)
[END IMPORTS ANALYSIS - 3 DLLs imported]

[INFO] Entry point RVA: 0x2F5E
[INFO] Machine type: x86 (32-bit)
[INFO] Number of sections: 3
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x2000, Raw=0x200, Size=0x1000
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/module_4.exe':
  - Section '.text': 4096 bytes at offset 0x200
[+] Success: Extracted 4096 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/module_4.exe_shellcode.bin'
[INFO] SHA256: 8afff5fbdb561f16a69c1e1a060d9fdbb36368fca0a90a9b7f3f2f5e0af35e75
[INFO] Entropy: 5.1305 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: mscoree.dll
    - Function: _CorExeMain (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x86 (32-bit)
[INFO] Number of sections: 4
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/rednefed_swodniw.exe':
  - Section '.text': 512 bytes at offset 0x400
[+] Success: Extracted 512 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/rednefed_swodniw.exe_shellcode.bin'
[INFO] SHA256: b9434abf0961eb228381f4257296710356df474fb787e4479b0c84558b176bc4
[INFO] Entropy: 2.6678 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: CloseHandle (Hint: 1)
    - Function: GetProcAddress (Hint: 2)
    - Function: LoadLibraryA (Hint: 3)
    - Function: LocalAlloc (Hint: 4)
    - Function: LocalFree (Hint: 5)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x1A00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/a.exe':
  - Section '.text': 6656 bytes at offset 0x600
[+] Success: Extracted 6656 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/a.exe_shellcode.bin'
[INFO] SHA256: 6b196d641153e7c4b01e1312b2ffce97959a16c0eddc2905a1cb406d4b75a615
[INFO] Entropy: 5.8785 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: KERNEL32.dll
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetLastError (Hint: 630)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: signal (Hint: 1063)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: vfprintf (Hint: 1123)
[END IMPORTS ANALYSIS - 2 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x86 (32-bit)
[INFO] Number of sections: 4
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/redows.exe':
  - Section '.text': 512 bytes at offset 0x400
[+] Success: Extracted 512 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/redows.exe_shellcode.bin'
[INFO] SHA256: b9434abf0961eb228381f4257296710356df474fb787e4479b0c84558b176bc4
[INFO] Entropy: 2.6678 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: CloseHandle (Hint: 1)
    - Function: GetProcAddress (Hint: 2)
    - Function: LoadLibraryA (Hint: 3)
    - Function: LocalAlloc (Hint: 4)
    - Function: LocalFree (Hint: 5)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0xAFE00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/icegaboon_envenomate.exe':
  - Section '.text': 720384 bytes at offset 0x600
[+] Success: Extracted 720384 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/icegaboon_envenomate.exe_shellcode.bin'
[INFO] SHA256: 2de721c1a964e8338306f4e425f7aca3435ed46e12303206ca68a863b8f085c4
[INFO] Entropy: 6.1430 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: CryptAcquireContextA (Hint: 1194)
    - Function: CryptGenRandom (Hint: 1211)
    - Function: CryptReleaseContext (Hint: 1221)
  Imported DLL: bcrypt.dll
    - Function: BCryptCloseAlgorithmProvider (Hint: 3)
    - Function: BCryptDestroyKey (Hint: 15)
    - Function: BCryptEncrypt (Hint: 19)
    - Function: BCryptGenerateSymmetricKey (Hint: 32)
    - Function: BCryptGetProperty (Hint: 34)
    - Function: BCryptOpenAlgorithmProvider (Hint: 39)
    - Function: BCryptSetProperty (Hint: 53)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CreateSemaphoreW (Hint: 246)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetCurrentThreadId (Hint: 557)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleHandleW (Hint: 654)
    - Function: GetProcAddress (Hint: 710)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDBCSLeadByteEx (Hint: 919)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: LoadLibraryW (Hint: 991)
    - Function: MultiByteToWideChar (Hint: 1036)
    - Function: RaiseException (Hint: 1153)
    - Function: ReleaseSemaphore (Hint: 1196)
    - Function: RtlCaptureContext (Hint: 1223)
    - Function: RtlLookupFunctionEntry (Hint: 1230)
    - Function: RtlUnwindEx (Hint: 1236)
    - Function: RtlVirtualUnwind (Hint: 1237)
    - Function: SetLastError (Hint: 1334)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsAlloc (Hint: 1443)
    - Function: TlsFree (Hint: 1444)
    - Function: TlsGetValue (Hint: 1445)
    - Function: TlsSetValue (Hint: 1446)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForSingleObject (Hint: 1503)
    - Function: WideCharToMultiByte (Hint: 1547)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: ___lc_codepage_func (Hint: 64)
    - Function: ___mb_cur_max_func (Hint: 67)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _errno (Hint: 190)
    - Function: _filelengthi64 (Hint: 210)
    - Function: _fileno (Hint: 211)
    - Function: _fmode (Hint: 220)
    - Function: _fstat64 (Hint: 234)
    - Function: _initterm (Hint: 285)
    - Function: _lseeki64 (Hint: 396)
    - Function: _onexit (Hint: 553)
    - Function: _strnicmp (Hint: 658)
    - Function: _vscprintf (Hint: 738)
    - Function: _vsnprintf (Hint: 744)
    - Function: _wfopen (Hint: 832)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fclose (Hint: 940)
    - Function: fflush (Hint: 943)
    - Function: fgetpos (Hint: 945)
    - Function: fopen (Hint: 953)
    - Function: fprintf (Hint: 956)
    - Function: fputc (Hint: 958)
    - Function: fputs (Hint: 959)
    - Function: fread (Hint: 962)
    - Function: free (Hint: 963)
    - Function: fsetpos (Hint: 971)
    - Function: fwrite (Hint: 976)
    - Function: getc (Hint: 980)
    - Function: getwc (Hint: 985)
    - Function: isspace (Hint: 998)
    - Function: iswctype (Hint: 1004)
    - Function: localeconv (Hint: 1017)
    - Function: malloc (Hint: 1023)
    - Function: memchr (Hint: 1029)
    - Function: memcmp (Hint: 1030)
    - Function: memcpy (Hint: 1031)
    - Function: memmove (Hint: 1032)
    - Function: memset (Hint: 1033)
    - Function: putc (Hint: 1043)
    - Function: putwc (Hint: 1046)
    - Function: realloc (Hint: 1052)
    - Function: setlocale (Hint: 1061)
    - Function: setvbuf (Hint: 1062)
    - Function: signal (Hint: 1063)
    - Function: strcmp (Hint: 1079)
    - Function: strcoll (Hint: 1080)
    - Function: strcpy_s (Hint: 1082)
    - Function: strerror (Hint: 1084)
    - Function: strftime (Hint: 1085)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strxfrm (Hint: 1101)
    - Function: towlower (Hint: 1118)
    - Function: towupper (Hint: 1119)
    - Function: ungetc (Hint: 1120)
    - Function: ungetwc (Hint: 1121)
    - Function: vfprintf (Hint: 1123)
    - Function: wcscoll (Hint: 1144)
    - Function: wcsftime (Hint: 1148)
    - Function: wcslen (Hint: 1149)
    - Function: wcsxfrm (Hint: 1168)
    - Function: _write (Hint: 1212)
    - Function: _read (Hint: 1254)
    - Function: _fileno (Hint: 1281)
    - Function: _fdopen (Hint: 1285)
    - Function: _close (Hint: 1301)
  Imported DLL: USER32.dll
    - Function: CallNextHookEx (Hint: 31)
    - Function: DispatchMessageA (Hint: 185)
    - Function: GetMessageA (Hint: 380)
    - Function: SetWindowsHookExA (Hint: 856)
    - Function: TranslateMessage (Hint: 897)
    - Function: UnhookWindowsHookEx (Hint: 901)
  Imported DLL: WINHTTP.dll
    - Function: WinHttpCloseHandle (Hint: 9)
    - Function: WinHttpConnect (Hint: 10)
    - Function: WinHttpCrackUrl (Hint: 22)
    - Function: WinHttpOpen (Hint: 39)
    - Function: WinHttpOpenRequest (Hint: 40)
    - Function: WinHttpReceiveResponse (Hint: 63)
    - Function: WinHttpSendRequest (Hint: 66)
[END IMPORTS ANALYSIS - 6 DLLs imported]

[INFO] Entry point RVA: 0x5DFC0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x92E00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/loader_1_fixed.exe':
  - Section '.text': 601600 bytes at offset 0x600
[+] Success: Extracted 601600 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/loader_1_fixed.exe_shellcode.bin'
[INFO] SHA256: 2955e99fbbbcbd38dbe45bc8f0efa0b15104e956ba1df1b96573d279a277b68d
[INFO] Entropy: 6.1772 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14C0
[INFO] Machine type: x86 (32-bit)
[INFO] Number of sections: 17
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2000
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/monogogo_win_exploit_silent.exe':
  - Section '.text': 8192 bytes at offset 0x600
[+] Success: Extracted 8192 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/monogogo_win_exploit_silent.exe_shellcode.bin'
[INFO] SHA256: 97486947b440a1eb3bae03657aa3636db5214a66d799df0b0097d226ebbd66f8
[INFO] Entropy: 5.8238 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: CloseServiceHandle (Hint: 1088)
    - Function: OpenSCManagerA (Hint: 1512)
    - Function: OpenServiceA (Hint: 1514)
    - Function: RegCloseKey (Hint: 1569)
    - Function: RegOpenKeyExA (Hint: 1617)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 136)
    - Function: CreateThread (Hint: 247)
    - Function: DeleteCriticalSection (Hint: 277)
    - Function: EnterCriticalSection (Hint: 310)
    - Function: FreeLibrary (Hint: 433)
    - Function: GetEnvironmentVariableA (Hint: 576)
    - Function: GetFileAttributesA (Hint: 584)
    - Function: GetLastError (Hint: 617)
    - Function: GetModuleHandleA (Hint: 637)
    - Function: GetProcAddress (Hint: 694)
    - Function: GetStartupInfoA (Hint: 729)
    - Function: InitializeCriticalSection (Hint: 877)
    - Function: LeaveCriticalSection (Hint: 973)
    - Function: LoadLibraryA (Hint: 977)
    - Function: SetUnhandledExceptionFilter (Hint: 1370)
    - Function: Sleep (Hint: 1386)
    - Function: TlsGetValue (Hint: 1421)
    - Function: VirtualProtect (Hint: 1469)
    - Function: VirtualQuery (Hint: 1472)
    - Function: WaitForMultipleObjects (Hint: 1479)
  Imported DLL: msvcrt.dll
    - Function: __getmainargs (Hint: 58)
    - Function: __initenv (Hint: 59)
    - Function: __lconv_init (Hint: 68)
    - Function: __p__acmdln (Hint: 76)
    - Function: __p__commode (Hint: 78)
    - Function: __p__fmode (Hint: 83)
    - Function: __set_app_type (Hint: 104)
    - Function: __setusermatherr (Hint: 107)
    - Function: _amsg_exit (Hint: 142)
    - Function: _cexit (Hint: 159)
    - Function: _initterm (Hint: 338)
    - Function: _iob (Hint: 342)
    - Function: _onexit (Hint: 570)
    - Function: abort (Hint: 922)
    - Function: calloc (Hint: 935)
    - Function: exit (Hint: 945)
    - Function: fprintf (Hint: 962)
    - Function: free (Hint: 969)
    - Function: fwrite (Hint: 982)
    - Function: malloc (Hint: 1027)
    - Function: memcpy (Hint: 1035)
    - Function: rand (Hint: 1053)
    - Function: signal (Hint: 1064)
    - Function: srand (Hint: 1070)
    - Function: strlen (Hint: 1084)
    - Function: strncmp (Hint: 1087)
    - Function: vfprintf (Hint: 1121)
    - Function: time (Hint: 713)
  Imported DLL: WS2_32.dll
    - Function: WSACleanup (Hint: 27)
    - Function: WSAStartup (Hint: 85)
[END IMPORTS ANALYSIS - 4 DLLs imported]

[INFO] Entry point RVA: 0x73A80
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 15
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x25AC00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/gordito.exe':
  - Section '.text': 2468864 bytes at offset 0x600
[+] Success: Extracted 2468864 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/gordito.exe_shellcode.bin'
[INFO] SHA256: 9583c4cdcb4ed36866473d8dd03af1775a8a0b424a777fc84fcb7d3005f3a044
[INFO] Entropy: 6.2236 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WerSetFlags (Hint: 0)
    - Function: WerGetFlags (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: TlsAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: RtlVirtualUnwind (Hint: 0)
    - Function: RtlLookupFunctionEntry (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: RaiseFailFastException (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: LoadLibraryExW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetErrorMode (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetCurrentThreadId (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
    - Function: AddVectoredContinueHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x777A0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 15
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2BB400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/uhmento.exe':
  - Section '.text': 2864128 bytes at offset 0x600
[+] Success: Extracted 2864128 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/uhmento.exe_shellcode.bin'
[INFO] SHA256: c1577966b177504d015fa3e1e5afb56580cc887e6aa982f28bd6f0f354e462cd
[INFO] Entropy: 6.2092 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WerSetFlags (Hint: 0)
    - Function: WerGetFlags (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: TlsAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: RtlVirtualUnwind (Hint: 0)
    - Function: RtlLookupFunctionEntry (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: RaiseFailFastException (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: LoadLibraryExW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetErrorMode (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetCurrentThreadId (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
    - Function: AddVectoredContinueHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x5DF80
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x93E00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/poopunscoop.exe':
  - Section '.text': 605696 bytes at offset 0x600
[+] Success: Extracted 605696 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/poopunscoop.exe_shellcode.bin'
[INFO] SHA256: 47a4e7488734a36bbd47d61d41d0752eec991a3397406d3d21efb9c2b05f4111
[INFO] Entropy: 6.1748 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 4
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/rsx64.exe':
  - Section '.text': 1024 bytes at offset 0x400
[+] Success: Extracted 1024 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/rsx64.exe_shellcode.bin'
[INFO] SHA256: b7110ceff89e3d46099524c271164fa138cfc5153cd42c947d2a2f8568c15d01
[INFO] Entropy: 3.3405 bits/byte

[IMPORTS ANALYSIS]
[END IMPORTS ANALYSIS - 0 DLLs imported]

[INFO] Entry point RVA: 0x63BA0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x244000
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/chompchomp.exe':
  - Section '.text': 2375680 bytes at offset 0x600
[+] Success: Extracted 2375680 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/chompchomp.exe_shellcode.bin'
[INFO] SHA256: 7ef17fd6954e53b02bf9ce05e78d702a67fa14f736a9c5d3f3594cee400685bc
[INFO] Entropy: 6.1686 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0xA400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/cwaytzar.exe':
  - Section '.text': 41984 bytes at offset 0x600
[+] Success: Extracted 41984 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/cwaytzar.exe_shellcode.bin'
[INFO] SHA256: 025012a703ec83954de6e27c811de07c7ac9934ba86fbbf520f1ac7cea2de0c9
[INFO] Entropy: 6.1969 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: AdjustTokenPrivileges (Hint: 1032)
    - Function: AllocateAndInitializeSid (Hint: 1033)
    - Function: CheckTokenMembership (Hint: 1096)
    - Function: FreeSid (Hint: 1310)
    - Function: LookupPrivilegeValueA (Hint: 1431)
    - Function: OpenProcessToken (Hint: 1534)
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExW (Hint: 1653)
    - Function: RegSaveKeyW (Hint: 1676)
    - Function: RegSetValueExW (Hint: 1682)
  Imported DLL: dbghelp.dll
    - Function: MiniDumpWriteDump (Hint: 31)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CopyFileA (Hint: 177)
    - Function: CreateFileA (Hint: 204)
    - Function: CreateToolhelp32Snapshot (Hint: 261)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: DeleteFileA (Hint: 285)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetCurrentProcess (Hint: 552)
    - Function: GetFileSize (Hint: 609)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleFileNameA (Hint: 649)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: GetTempPathA (Hint: 781)
    - Function: GetTempPathW (Hint: 782)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDBCSLeadByteEx (Hint: 919)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: MultiByteToWideChar (Hint: 1036)
    - Function: OpenProcess (Hint: 1069)
    - Function: Process32FirstW (Hint: 1098)
    - Function: Process32NextW (Hint: 1100)
    - Function: ReadFile (Hint: 1170)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WideCharToMultiByte (Hint: 1547)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: ___lc_codepage_func (Hint: 64)
    - Function: ___mb_cur_max_func (Hint: 67)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _errno (Hint: 190)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: fwprintf (Hint: 973)
    - Function: _wcsicmp (Hint: 780)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: fputc (Hint: 958)
    - Function: fputwc (Hint: 960)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: getenv (Hint: 982)
    - Function: localeconv (Hint: 1017)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: memset (Hint: 1033)
    - Function: signal (Hint: 1063)
    - Function: strcat (Hint: 1076)
    - Function: strerror (Hint: 1084)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strrchr (Hint: 1093)
    - Function: vfprintf (Hint: 1123)
    - Function: wcslen (Hint: 1149)
    - Function: wcstombs (Hint: 1165)
  Imported DLL: ole32.dll
    - Function: CoCreateInstance (Hint: 31)
    - Function: CoInitializeEx (Hint: 86)
    - Function: CoUninitialize (Hint: 133)
  Imported DLL: SHELL32.dll
    - Function: ShellExecuteA (Hint: 336)
  Imported DLL: USER32.dll
    - Function: CallNextHookEx (Hint: 31)
    - Function: DispatchMessageA (Hint: 185)
    - Function: GetKeyboardState (Hint: 357)
    - Function: GetMessageA (Hint: 380)
    - Function: SetWindowsHookExA (Hint: 856)
    - Function: ToAscii (Hint: 886)
    - Function: TranslateMessage (Hint: 897)
    - Function: UnhookWindowsHookEx (Hint: 901)
  Imported DLL: WINHTTP.dll
    - Function: WinHttpCloseHandle (Hint: 9)
    - Function: WinHttpConnect (Hint: 10)
    - Function: WinHttpCrackUrl (Hint: 22)
    - Function: WinHttpOpen (Hint: 39)
    - Function: WinHttpOpenRequest (Hint: 40)
    - Function: WinHttpReceiveResponse (Hint: 63)
    - Function: WinHttpSendRequest (Hint: 66)
    - Function: WinHttpWriteData (Hint: 81)
[END IMPORTS ANALYSIS - 8 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x4200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/installer_4.exe':
  - Section '.text': 16896 bytes at offset 0x600
[+] Success: Extracted 16896 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/installer_4.exe_shellcode.bin'
[INFO] SHA256: ff5e04ed8f48b6f99f7bf7a16c28521a57a076d0995498142f90f4593a2ae9ce
[INFO] Entropy: 5.6976 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: CryptAcquireContextA (Hint: 1194)
    - Function: CryptCreateHash (Hint: 1197)
    - Function: CryptDecrypt (Hint: 1198)
    - Function: CryptDeriveKey (Hint: 1199)
    - Function: CryptDestroyHash (Hint: 1200)
    - Function: CryptDestroyKey (Hint: 1201)
    - Function: CryptGenRandom (Hint: 1211)
    - Function: CryptHashData (Hint: 1218)
    - Function: CryptReleaseContext (Hint: 1221)
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExA (Hint: 1652)
    - Function: RegQueryValueExA (Hint: 1665)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CreateThread (Hint: 252)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: ExitProcess (Hint: 366)
    - Function: GetLastError (Hint: 630)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDebuggerPresent (Hint: 920)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualAlloc (Hint: 1486)
    - Function: VirtualFree (Hint: 1489)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForSingleObject (Hint: 1503)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: _time64 (Hint: 693)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: memmove (Hint: 1032)
    - Function: rand (Hint: 1051)
    - Function: signal (Hint: 1063)
    - Function: srand (Hint: 1072)
    - Function: strcat_s (Hint: 1077)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strstr (Hint: 1095)
    - Function: vfprintf (Hint: 1123)
  Imported DLL: WININET.dll
    - Function: InternetCloseHandle (Hint: 145)
    - Function: InternetOpenA (Hint: 194)
    - Function: InternetOpenUrlA (Hint: 195)
    - Function: InternetReadFile (Hint: 202)
  Imported DLL: libgcc_s_seh-1.dll
    - Function: _Unwind_Resume (Hint: 15)
  Imported DLL: libstdc++-6.dll
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv (Hint: 731)
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv (Hint: 743)
    - Function: _ZNSaIcEC1Ev (Hint: 1265)
    - Function: _ZNSaIcED1Ev (Hint: 1268)
    - Function: _ZNSaIcED2Ev (Hint: 1269)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv (Hint: 3670)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEy (Hint: 3673)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcRKS3_ (Hint: 3675)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv (Hint: 3685)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEy (Hint: 3686)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsEPcPKcS7_ (Hint: 3689)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendEPKc (Hint: 3711)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc (Hint: 3739)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERyy (Hint: 3769)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_ (Hint: 3775)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev (Hint: 3808)
    - Function: _ZSt17__throw_bad_allocv (Hint: 4624)
    - Function: _ZSt19__throw_logic_errorPKc (Hint: 4638)
    - Function: _ZSt20__throw_length_errorPKc (Hint: 4646)
    - Function: _ZdaPv (Hint: 5611)
    - Function: _ZdlPvy (Hint: 5621)
    - Function: _Znay (Hint: 5623)
    - Function: _Znwy (Hint: 5627)
    - Function: __cxa_begin_catch (Hint: 5637)
    - Function: __cxa_end_catch (Hint: 5642)
    - Function: __cxa_rethrow (Hint: 5653)
    - Function: __gxx_personality_seh0 (Hint: 5670)
[END IMPORTS ANALYSIS - 6 DLLs imported]

[INFO] Entry point RVA: 0x14C0
[INFO] Machine type: x86 (32-bit)
[INFO] Number of sections: 17
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x3800
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/mindfr34k.exe':
  - Section '.text': 14336 bytes at offset 0x600
[+] Success: Extracted 14336 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/mindfr34k.exe_shellcode.bin'
[INFO] SHA256: 858041585687e4b6c68b2d736815e42463756d70f7ea7bfd6600c74caa49d5f3
[INFO] Entropy: 5.9989 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: GetUserNameA (Hint: 1363)
    - Function: RegCloseKey (Hint: 1569)
    - Function: RegOpenKeyExA (Hint: 1617)
    - Function: RegQueryValueExA (Hint: 1630)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 136)
    - Function: CreateToolhelp32Snapshot (Hint: 256)
    - Function: DeleteCriticalSection (Hint: 277)
    - Function: EnterCriticalSection (Hint: 310)
    - Function: FreeLibrary (Hint: 433)
    - Function: GetComputerNameA (Hint: 484)
    - Function: GetLastError (Hint: 617)
    - Function: GetModuleHandleA (Hint: 637)
    - Function: GetProcAddress (Hint: 694)
    - Function: GetStartupInfoA (Hint: 729)
    - Function: GetSystemInfo (Hint: 749)
    - Function: GlobalMemoryStatusEx (Hint: 836)
    - Function: InitializeCriticalSection (Hint: 877)
    - Function: LeaveCriticalSection (Hint: 973)
    - Function: LoadLibraryA (Hint: 977)
    - Function: Process32First (Hint: 1084)
    - Function: Process32Next (Hint: 1086)
    - Function: SetUnhandledExceptionFilter (Hint: 1370)
    - Function: Sleep (Hint: 1386)
    - Function: TlsGetValue (Hint: 1421)
    - Function: VirtualProtect (Hint: 1469)
    - Function: VirtualQuery (Hint: 1472)
  Imported DLL: msvcrt.dll
    - Function: __getmainargs (Hint: 58)
    - Function: __initenv (Hint: 59)
    - Function: __lconv_init (Hint: 68)
    - Function: __p__acmdln (Hint: 76)
    - Function: __p__commode (Hint: 78)
    - Function: __p__fmode (Hint: 83)
    - Function: __set_app_type (Hint: 104)
    - Function: __setusermatherr (Hint: 107)
    - Function: _amsg_exit (Hint: 142)
    - Function: _cexit (Hint: 159)
    - Function: _initterm (Hint: 338)
    - Function: _iob (Hint: 342)
    - Function: _onexit (Hint: 570)
    - Function: abort (Hint: 922)
    - Function: calloc (Hint: 935)
    - Function: exit (Hint: 945)
    - Function: fprintf (Hint: 962)
    - Function: free (Hint: 969)
    - Function: fwrite (Hint: 982)
    - Function: malloc (Hint: 1027)
    - Function: memcpy (Hint: 1035)
    - Function: signal (Hint: 1064)
    - Function: strlen (Hint: 1084)
    - Function: strncmp (Hint: 1087)
    - Function: vfprintf (Hint: 1121)
  Imported DLL: USER32.dll
    - Function: CallNextHookEx (Hint: 30)
    - Function: SetWindowsHookExA (Hint: 804)
  Imported DLL: WINHTTP.dll
    - Function: WinHttpAddRequestHeaders (Hint: 5)
    - Function: WinHttpCloseHandle (Hint: 9)
    - Function: WinHttpConnect (Hint: 10)
    - Function: WinHttpOpen (Hint: 39)
    - Function: WinHttpOpenRequest (Hint: 40)
    - Function: WinHttpReceiveResponse (Hint: 50)
    - Function: WinHttpSendRequest (Hint: 53)
  Imported DLL: libgcc_s_dw2-1.dll
    - Function: _Unwind_Resume (Hint: 15)
    - Function: __deregister_frame_info (Hint: 37)
    - Function: __register_frame_info (Hint: 107)
    - Function: __udivdi3 (Hint: 119)
    - Function: __umoddi3 (Hint: 121)
  Imported DLL: libstdc++-6.dll
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13get_allocatorEv (Hint: 772)
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4cendEv (Hint: 786)
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv (Hint: 794)
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5emptyEv (Hint: 798)
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6cbeginEv (Hint: 804)
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8capacityEv (Hint: 818)
    - Function: _ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE5c_strEv (Hint: 857)
    - Function: _ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE6lengthEv (Hint: 866)
    - Function: _ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE7_M_dataEv (Hint: 869)
    - Function: _ZNKSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEE3strEv (Hint: 885)
    - Function: _ZNSaIcEC1Ev (Hint: 1330)
    - Function: _ZNSaIcED1Ev (Hint: 1333)
    - Function: _ZNSaIwEC1Ev (Hint: 1336)
    - Function: _ZNSaIwED1Ev (Hint: 1339)
    - Function: _ZNSaIwED2Ev (Hint: 1340)
    - Function: _ZNSolsEPFRSt8ios_baseS0_E (Hint: 1587)
    - Function: _ZNSolsEi (Hint: 1595)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE3endEv (Hint: 3715)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5beginEv (Hint: 3721)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendEPKc (Hint: 3729)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendERKS4_ (Hint: 3731)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6insertEjPKc (Hint: 3748)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6insertEjRKS4_ (Hint: 3750)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8pop_backEv (Hint: 3784)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_ (Hint: 3793)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_ (Hint: 3795)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EjcRKS3_ (Hint: 3804)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev (Hint: 3826)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEj (Hint: 3833)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEpLERKS4_ (Hint: 3835)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEpLEc (Hint: 3837)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE10_M_disposeEv (Hint: 3839)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE11_M_capacityEj (Hint: 3842)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_Alloc_hiderC1EPwRKS3_ (Hint: 3844)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_M_local_dataEv (Hint: 3854)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_M_set_lengthEj (Hint: 3855)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE7_M_dataEPw (Hint: 3908)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE9_M_createERjj (Hint: 3938)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEED1Ev (Hint: 3977)
    - Function: _ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEEC1Ev (Hint: 4142)
    - Function: _ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEED1Ev (Hint: 4148)
    - Function: _ZSt19__throw_logic_errorPKc (Hint: 4656)
    - Function: _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc (Hint: 4790)
    - Function: _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c (Hint: 4793)
    - Function: _ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St5_Setw (Hint: 4798)
    - Function: _ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St8_SetfillIS3_E (Hint: 4800)
    - Function: __cxa_begin_catch (Hint: 5643)
    - Function: __cxa_end_catch (Hint: 5648)
    - Function: __cxa_rethrow (Hint: 5659)
    - Function: __gxx_personality_v0 (Hint: 5676)
[END IMPORTS ANALYSIS - 7 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/compromise_1.exe':
  - Section '.text': 8704 bytes at offset 0x600
[+] Success: Extracted 8704 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/compromise_1.exe_shellcode.bin'
[INFO] SHA256: 4c7cec408533abfd3fc438b5522627867acbce7027be6c1dca00460deb33c6e5
[INFO] Entropy: 5.9143 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: AdjustTokenPrivileges (Hint: 1032)
    - Function: CryptAcquireContextA (Hint: 1194)
    - Function: CryptCreateHash (Hint: 1197)
    - Function: CryptDecrypt (Hint: 1198)
    - Function: CryptDeriveKey (Hint: 1199)
    - Function: CryptDestroyHash (Hint: 1200)
    - Function: CryptDestroyKey (Hint: 1201)
    - Function: CryptGenRandom (Hint: 1211)
    - Function: CryptHashData (Hint: 1218)
    - Function: CryptReleaseContext (Hint: 1221)
    - Function: LookupPrivilegeValueA (Hint: 1431)
    - Function: OpenProcessToken (Hint: 1534)
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExA (Hint: 1652)
    - Function: RegQueryValueExA (Hint: 1665)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CreateThread (Hint: 252)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetCurrentProcess (Hint: 552)
    - Function: GetLastError (Hint: 630)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualAlloc (Hint: 1486)
    - Function: VirtualFree (Hint: 1489)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForSingleObject (Hint: 1503)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: _time64 (Hint: 693)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: rand (Hint: 1051)
    - Function: signal (Hint: 1063)
    - Function: srand (Hint: 1072)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strstr (Hint: 1095)
    - Function: vfprintf (Hint: 1123)
  Imported DLL: libstdc++-6.dll
    - Function: _ZdaPv (Hint: 5611)
    - Function: _Znay (Hint: 5623)
[END IMPORTS ANALYSIS - 4 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 6
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x400
[INFO] Entry point is in section '.text'
[DEBUG] Processing section '.stub': RVA=0x5000, Raw=0xE00, Size=0x2000
[+] Found 2 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/modified_skeeterspit.exe':
  - Section '.text': 1024 bytes at offset 0x400
  - Section '.stub': 8192 bytes at offset 0xE00
[+] Success: Extracted 9216 bytes from 2 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/modified_skeeterspit.exe_shellcode.bin'
[INFO] SHA256: 7d6fc0bad5e09ebcacae62b3a09d39366b1732b741ae633ab88bfb668df7ced0
[INFO] Entropy: 0.6591 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: CloseServiceHandle (Hint: 1102)
    - Function: ControlService (Hint: 1107)
    - Function: OpenSCManagerW (Hint: 1536)
    - Function: OpenServiceW (Hint: 1538)
    - Function: QueryServiceStatus (Hint: 1593)
  Imported DLL: KERNEL32.dll
    - Function: ExitProcess (Hint: 366)
    - Function: GetCurrentProcessId (Hint: 553)
    - Function: GetProcessHeap (Hint: 716)
    - Function: GetTickCount64 (Hint: 800)
    - Function: QueryPerformanceCounter (Hint: 1131)
  Imported DLL: ntdll.dll
    - Function: RtlGetVersion (Hint: 1145)
[END IMPORTS ANALYSIS - 3 DLLs imported]

[INFO] Entry point RVA: 0x14D0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 10
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x6C00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/mdropper.exe':
  - Section '.text': 27648 bytes at offset 0x400
[+] Success: Extracted 27648 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/mdropper.exe_shellcode.bin'
[INFO] SHA256: 42ab7780c4865d9d37d6b9de415858178128acc0ae4caa83080b4fbd6869a228
[INFO] Entropy: 6.2869 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CreateProcessA (Hint: 234)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetLastError (Hint: 630)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: GetTempPathA (Hint: 781)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDBCSLeadByteEx (Hint: 919)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: MultiByteToWideChar (Hint: 1036)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WideCharToMultiByte (Hint: 1547)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: ___lc_codepage_func (Hint: 64)
    - Function: ___mb_cur_max_func (Hint: 67)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _errno (Hint: 190)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fclose (Hint: 940)
    - Function: fopen (Hint: 953)
    - Function: fprintf (Hint: 956)
    - Function: fputc (Hint: 958)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: localeconv (Hint: 1017)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: signal (Hint: 1063)
    - Function: strerror (Hint: 1084)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: vfprintf (Hint: 1123)
    - Function: wcslen (Hint: 1149)
[END IMPORTS ANALYSIS - 2 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x8000
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/c_klogging.exe':
  - Section '.text': 32768 bytes at offset 0x600
[+] Success: Extracted 32768 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/c_klogging.exe_shellcode.bin'
[INFO] SHA256: 1989ebd65326c3831079a2f61f633fdbb78953bbfedc68dfda6a0c864520837e
[INFO] Entropy: 2.4157 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: 
[END IMPORTS ANALYSIS - 2 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 20
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x20DC00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/quicky5.exe':
  - Section '.text': 2153472 bytes at offset 0x600
[+] Success: Extracted 2153472 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/quicky5.exe_shellcode.bin'
[INFO] SHA256: 80167864433ee0f12fdabbb514b0247c5d14a29804a670a28c53185b78af4560
[INFO] Entropy: 6.1625 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExA (Hint: 1652)
    - Function: RegSetValueExA (Hint: 1681)
  Imported DLL: KERNEL32.dll
    - Function: AddVectoredExceptionHandler (Hint: 20)
    - Function: CloseHandle (Hint: 141)
    - Function: CreateEventA (Hint: 197)
    - Function: CreateFileA (Hint: 204)
    - Function: CreateIoCompletionPort (Hint: 217)
    - Function: CreateThread (Hint: 252)
    - Function: CreateWaitableTimerExW (Hint: 266)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: DuplicateHandle (Hint: 313)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: ExitProcess (Hint: 366)
    - Function: FreeEnvironmentStringsW (Hint: 442)
    - Function: GetConsoleMode (Hint: 525)
    - Function: GetEnvironmentStringsW (Hint: 587)
    - Function: GetLastError (Hint: 630)
    - Function: GetProcAddress (Hint: 710)
    - Function: GetProcessAffinityMask (Hint: 711)
    - Function: GetQueuedCompletionStatusEx (Hint: 739)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: GetStdHandle (Hint: 746)
    - Function: GetSystemDirectoryA (Hint: 759)
    - Function: GetSystemInfo (Hint: 763)
    - Function: GetThreadContext (Hint: 783)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDBCSLeadByteEx (Hint: 919)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: LoadLibraryA (Hint: 988)
    - Function: LoadLibraryW (Hint: 991)
    - Function: MultiByteToWideChar (Hint: 1036)
    - Function: PostQueuedCompletionStatus (Hint: 1089)
    - Function: ResumeThread (Hint: 1221)
    - Function: SetConsoleCtrlHandler (Hint: 1261)
    - Function: SetErrorMode (Hint: 1305)
    - Function: SetEvent (Hint: 1306)
    - Function: SetProcessPriorityBoost (Hint: 1352)
    - Function: SetThreadContext (Hint: 1368)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: SetWaitableTimer (Hint: 1403)
    - Function: Sleep (Hint: 1410)
    - Function: SuspendThread (Hint: 1418)
    - Function: SwitchToThread (Hint: 1420)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualAlloc (Hint: 1486)
    - Function: VirtualFree (Hint: 1489)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForMultipleObjects (Hint: 1501)
    - Function: WaitForSingleObject (Hint: 1503)
    - Function: WideCharToMultiByte (Hint: 1547)
    - Function: WriteConsoleW (Hint: 1566)
    - Function: WriteFile (Hint: 1567)
    - Function: __C_specific_handler (Hint: 1584)
  Imported DLL: msvcrt.dll
    - Function: ___lc_codepage_func (Hint: 64)
    - Function: ___mb_cur_max_func (Hint: 67)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _beginthread (Hint: 134)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _errno (Hint: 190)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _lock (Hint: 387)
    - Function: _onexit (Hint: 553)
    - Function: _unlock (Hint: 714)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: fputc (Hint: 958)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: localeconv (Hint: 1017)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: signal (Hint: 1063)
    - Function: strerror (Hint: 1084)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: vfprintf (Hint: 1123)
    - Function: wcslen (Hint: 1149)
[END IMPORTS ANALYSIS - 3 DLLs imported]
[EXPORTS ANALYSIS - a.out.exe]
  Base Ordinal: 1
  Number of Functions: 1
  Number of Names: 1
    - Function: _cgo_dummy_export
[END EXPORTS ANALYSIS]
[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 4
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/defender_disabler.exe':
  - Section '.text': 512 bytes at offset 0x400
[+] Success: Extracted 512 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/defender_disabler.exe_shellcode.bin'
[INFO] SHA256: 526128094961cdd80a6ce5a14397d654d5c951e40b2e1c976aab821a864a85f1
[INFO] Entropy: 3.1073 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: KERNEL32.dll
    - Function: ExitProcess (Hint: 366)
    - Function: GetProcAddress (Hint: 710)
    - Function: LoadLibraryA (Hint: 988)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x63B80
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x234200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/punchanazi.exe':
  - Section '.text': 2310656 bytes at offset 0x600
[+] Success: Extracted 2310656 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/punchanazi.exe_shellcode.bin'
[INFO] SHA256: aec297a8dc66f222d95bc842707e3d7dc69554ee1f189a9cdc7a36458ae2036d
[INFO] Entropy: 6.1559 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x63AC0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x220200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/packed_rocksolid.exe':
  - Section '.text': 2228736 bytes at offset 0x600
[+] Success: Extracted 2228736 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/packed_rocksolid.exe_shellcode.bin'
[INFO] SHA256: 808ae9304f7f53121b5c1b29e48200619bbda36fba92ba08c3eeef5c9384c0e9
[INFO] Entropy: 6.1531 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x777A0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 8
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2BB400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/uhmento_OW.exe':
  - Section '.text': 2864128 bytes at offset 0x600
[+] Success: Extracted 2864128 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/uhmento_OW.exe_shellcode.bin'
[INFO] SHA256: bc046f97d48825a5444dcc21ce369fc195e157f278530bc120d484fb3be8583b
[INFO] Entropy: 6.2094 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WerSetFlags (Hint: 0)
    - Function: WerGetFlags (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: TlsAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: RtlVirtualUnwind (Hint: 0)
    - Function: RtlLookupFunctionEntry (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: RaiseFailFastException (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: LoadLibraryExW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetErrorMode (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetCurrentThreadId (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
    - Function: AddVectoredContinueHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 4
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/stslsc.exe':
  - Section '.text': 1024 bytes at offset 0x400
[+] Success: Extracted 1024 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/stslsc.exe_shellcode.bin'
[INFO] SHA256: ee0e4ec840e6f89c2648aedb0845fa86623942ef932c8d6a726c5f4b60ed738c
[INFO] Entropy: 4.7956 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: KERNEL32.dll
    - Function: ExitProcess (Hint: 366)
    - Function: GetModuleHandleA (Hint: 651)
    - Function: GetProcAddress (Hint: 710)
    - Function: HeapAlloc (Hint: 863)
    - Function: HeapCreate (Hint: 865)
    - Function: HeapFree (Hint: 869)
    - Function: LoadLibraryA (Hint: 988)
    - Function: lstrlenA (Hint: 1611)
  Imported DLL: USER32.dll
    - Function: CallNextHookEx (Hint: 31)
    - Function: DispatchMessageA (Hint: 185)
    - Function: GetMessageA (Hint: 380)
    - Function: TranslateMessage (Hint: 897)
    - Function: UnhookWindowsHookEx (Hint: 901)
    - Function: wsprintfA (Hint: 958)
  Imported DLL: WS2_32.dll
    - Function: WSACleanup (Hint: 31)
    - Function: WSAStartup (Hint: 89)
    - Function: closesocket (Hint: 164)
    - Function: connect (Hint: 165)
    - Function: send (Hint: 192)
    - Function: socket (Hint: 196)
[END IMPORTS ANALYSIS - 3 DLLs imported]

[INFO] Entry point RVA: 0x14D0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x1E00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/immovable_force.exe':
  - Section '.text': 7680 bytes at offset 0x600
[+] Success: Extracted 7680 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/immovable_force.exe_shellcode.bin'
[INFO] SHA256: 5a24cdb65ac065f32b577b5cafc8b0fdc206e33b65444cc921dd3b62bc5adcee
[INFO] Entropy: 5.9277 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExA (Hint: 1652)
    - Function: RegQueryValueExA (Hint: 1665)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CreateToolhelp32Snapshot (Hint: 261)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: ExitProcess (Hint: 366)
    - Function: GetCurrentThread (Hint: 556)
    - Function: GetLastError (Hint: 630)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: GetThreadContext (Hint: 783)
    - Function: GlobalMemoryStatusEx (Hint: 852)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDebuggerPresent (Hint: 920)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: Process32First (Hint: 1097)
    - Function: Process32Next (Hint: 1099)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: __C_specific_handler (Hint: 1584)
  Imported DLL: msvcrt.dll
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: _stricmp (Hint: 648)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: signal (Hint: 1063)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strstr (Hint: 1095)
    - Function: vfprintf (Hint: 1123)
  Imported DLL: keylogger.dll
    - Function: run_keylogger (Hint: 1)
[END IMPORTS ANALYSIS - 4 DLLs imported]

[INFO] Entry point RVA: 0x60420
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0xBC600
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/tazdvl.exe':
  - Section '.text': 771584 bytes at offset 0x600
[+] Success: Extracted 771584 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/tazdvl.exe_shellcode.bin'
[INFO] SHA256: 8e1c0e06f3c82de22351f19075dacfb44e38827a0b3d6aa455bb7bf890f5a03b
[INFO] Entropy: 6.1810 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x1A00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/a_1.exe':
  - Section '.text': 6656 bytes at offset 0x600
[+] Success: Extracted 6656 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/a_1.exe_shellcode.bin'
[INFO] SHA256: 44b8806cb43af6cd2f25764063e8f2a3870e7043b61f43e0c5da81566a2e6ff0
[INFO] Entropy: 5.8625 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: KERNEL32.dll
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetLastError (Hint: 630)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: signal (Hint: 1063)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: vfprintf (Hint: 1123)
[END IMPORTS ANALYSIS - 2 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2A00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/persistence_1.exe':
  - Section '.text': 10752 bytes at offset 0x600
[+] Success: Extracted 10752 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/persistence_1.exe_shellcode.bin'
[INFO] SHA256: d30aa2ced0139ea84c37b6ffdf91365da1d117b3ece3e9353baf8bfbf658b1c0
[INFO] Entropy: 5.8643 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: libgcc_s_seh-1.dll
    - Function: _Unwind_Resume (Hint: 15)
  Imported DLL: libstdc++-6.dll
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv (Hint: 731)
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv (Hint: 743)
    - Function: _ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13get_allocatorEv (Hint: 768)
    - Function: _ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE4sizeEv (Hint: 790)
    - Function: _ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE7_M_dataEv (Hint: 804)
    - Function: _ZNKSt7__cxx1118basic_stringstreamIwSt11char_traitsIwESaIwEE3strEv (Hint: 822)
    - Function: _ZNSaIcEC1Ev (Hint: 1265)
    - Function: _ZNSaIcED1Ev (Hint: 1268)
    - Function: _ZNSaIcED2Ev (Hint: 1269)
    - Function: _ZNSaIwEC1ERKS_ (Hint: 1270)
    - Function: _ZNSaIwEC1Ev (Hint: 1271)
    - Function: _ZNSaIwED1Ev (Hint: 1274)
    - Function: _ZNSaIwED2Ev (Hint: 1275)
    - Function: _ZNSolsEPFRSoS_E (Hint: 1521)
    - Function: _ZNSt13basic_ostreamIwSt11char_traitsIwEElsEPFRS2_S3_E (Hint: 2385)
    - Function: _ZNSt13basic_ostreamIwSt11char_traitsIwEElsEi (Hint: 2394)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv (Hint: 3670)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEy (Hint: 3673)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcRKS3_ (Hint: 3675)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv (Hint: 3685)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEy (Hint: 3686)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc (Hint: 3739)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERyy (Hint: 3769)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev (Hint: 3808)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE10_M_disposeEv (Hint: 3821)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE11_M_capacityEy (Hint: 3824)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_Alloc_hiderC1EPwRKS3_ (Hint: 3826)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_M_local_dataEv (Hint: 3836)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_M_set_lengthEy (Hint: 3837)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_S_copy_charsEPwPKwS7_ (Hint: 3840)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE3endEv (Hint: 3848)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE5beginEv (Hint: 3854)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE6appendEPKw (Hint: 3862)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE6appendEPKwy (Hint: 3863)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE6appendERKS4_ (Hint: 3864)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE7_M_dataEPw (Hint: 3890)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE7reserveEy (Hint: 3915)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE9_M_createERyy (Hint: 3920)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1EOS4_ (Hint: 3926)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1ERKS3_ (Hint: 3930)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEED1Ev (Hint: 3959)
    - Function: _ZNSt7__cxx1118basic_stringstreamIwSt11char_traitsIwESaIwEEC1Ev (Hint: 4138)
    - Function: _ZNSt7__cxx1118basic_stringstreamIwSt11char_traitsIwESaIwEED1Ev (Hint: 4144)
    - Function: _ZNSt8ios_base4InitC1Ev (Hint: 4392)
    - Function: _ZNSt8ios_base4InitD1Ev (Hint: 4394)
    - Function: _ZSt19__throw_logic_errorPKc (Hint: 4638)
    - Function: _ZSt4cout (Hint: 4666)
    - Function: _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_ (Hint: 4667)
    - Function: _ZSt4endlIwSt11char_traitsIwEERSt13basic_ostreamIT_T0_ES6_ (Hint: 4668)
    - Function: _ZSt5wcerr (Hint: 4674)
    - Function: _ZSt5wcout (Hint: 4676)
    - Function: _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc (Hint: 4772)
    - Function: _ZStlsIwSt11char_traitsIwEERSt13basic_ostreamIT_T0_ES6_PKS3_ (Hint: 4791)
    - Function: _ZStlsIwSt11char_traitsIwESaIwEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE (Hint: 4801)
    - Function: __cxa_begin_catch (Hint: 5637)
    - Function: __cxa_end_catch (Hint: 5642)
    - Function: __cxa_rethrow (Hint: 5653)
    - Function: __gxx_personality_seh0 (Hint: 5670)
  Imported DLL: KERNEL32.dll
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleFileNameW (Hint: 650)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: signal (Hint: 1063)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: system (Hint: 1108)
    - Function: vfprintf (Hint: 1123)
    - Function: wcslen (Hint: 1149)
[END IMPORTS ANALYSIS - 4 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 5
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0xA00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/obfuscated_wingaypi.exe':
  - Section '.text': 2560 bytes at offset 0x400
[+] Success: Extracted 2560 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/obfuscated_wingaypi.exe_shellcode.bin'
[INFO] SHA256: f25884a93357dbba045e2cd8792db847e138d2502a72695aa9a512aeae44f6e7
[INFO] Entropy: 4.1531 bits/byte

[IMPORTS ANALYSIS]
[END IMPORTS ANALYSIS - 0 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0xA400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/cwaytzar_new.exe':
  - Section '.text': 41984 bytes at offset 0x600
[+] Success: Extracted 41984 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/cwaytzar_new.exe_shellcode.bin'
[INFO] SHA256: 939aa2f0663b106f6bd09cd9c9c993dee185b64590328710384a217ad2acd753
[INFO] Entropy: 6.2123 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: AdjustTokenPrivileges (Hint: 1032)
    - Function: AllocateAndInitializeSid (Hint: 1033)
    - Function: CheckTokenMembership (Hint: 1096)
    - Function: FreeSid (Hint: 1310)
    - Function: LookupPrivilegeValueA (Hint: 1431)
    - Function: OpenProcessToken (Hint: 1534)
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExW (Hint: 1653)
    - Function: RegSaveKeyW (Hint: 1676)
    - Function: RegSetValueExW (Hint: 1682)
  Imported DLL: dbghelp.dll
    - Function: MiniDumpWriteDump (Hint: 31)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CopyFileA (Hint: 177)
    - Function: CreateFileA (Hint: 204)
    - Function: CreateToolhelp32Snapshot (Hint: 261)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: DeleteFileA (Hint: 285)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetCurrentProcess (Hint: 552)
    - Function: GetFileSize (Hint: 609)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleFileNameA (Hint: 649)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: GetTempPathA (Hint: 781)
    - Function: GetTempPathW (Hint: 782)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDBCSLeadByteEx (Hint: 919)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: MultiByteToWideChar (Hint: 1036)
    - Function: OpenProcess (Hint: 1069)
    - Function: Process32FirstW (Hint: 1098)
    - Function: Process32NextW (Hint: 1100)
    - Function: ReadFile (Hint: 1170)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WideCharToMultiByte (Hint: 1547)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: ___lc_codepage_func (Hint: 64)
    - Function: ___mb_cur_max_func (Hint: 67)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _errno (Hint: 190)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: fwprintf (Hint: 973)
    - Function: _wcsicmp (Hint: 780)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: fputc (Hint: 958)
    - Function: fputwc (Hint: 960)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: getenv (Hint: 982)
    - Function: localeconv (Hint: 1017)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: memset (Hint: 1033)
    - Function: signal (Hint: 1063)
    - Function: strcat (Hint: 1076)
    - Function: strerror (Hint: 1084)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strrchr (Hint: 1093)
    - Function: vfprintf (Hint: 1123)
    - Function: wcslen (Hint: 1149)
    - Function: wcstombs (Hint: 1165)
  Imported DLL: ole32.dll
    - Function: CoCreateInstance (Hint: 31)
    - Function: CoInitializeEx (Hint: 86)
    - Function: CoUninitialize (Hint: 133)
  Imported DLL: SHELL32.dll
    - Function: ShellExecuteA (Hint: 336)
  Imported DLL: USER32.dll
    - Function: CallNextHookEx (Hint: 31)
    - Function: DispatchMessageA (Hint: 185)
    - Function: GetKeyboardState (Hint: 357)
    - Function: GetMessageA (Hint: 380)
    - Function: SetWindowsHookExA (Hint: 856)
    - Function: ToAscii (Hint: 886)
    - Function: TranslateMessage (Hint: 897)
    - Function: UnhookWindowsHookEx (Hint: 901)
  Imported DLL: WINHTTP.dll
    - Function: WinHttpCloseHandle (Hint: 9)
    - Function: WinHttpConnect (Hint: 10)
    - Function: WinHttpCrackUrl (Hint: 22)
    - Function: WinHttpOpen (Hint: 39)
    - Function: WinHttpOpenRequest (Hint: 40)
    - Function: WinHttpReceiveResponse (Hint: 63)
    - Function: WinHttpSendRequest (Hint: 66)
    - Function: WinHttpWriteData (Hint: 81)
[END IMPORTS ANALYSIS - 8 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 3
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/zombitkorus.exe':
  - Section '.text': 1024 bytes at offset 0x400
[+] Success: Extracted 1024 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/zombitkorus.exe_shellcode.bin'
[INFO] SHA256: 632b95900b9b3e01d0ab0fca4cbcce5dfbbc3492766266fb4870e348407eeb16
[INFO] Entropy: 4.5965 bits/byte

[IMPORTS ANALYSIS]
[END IMPORTS ANALYSIS - 0 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/modified_goofygoober_1.exe':
  - Section '.text': 8704 bytes at offset 0x600
[+] Success: Extracted 8704 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/modified_goofygoober_1.exe_shellcode.bin'
[INFO] SHA256: aef1fed4b9dc19b8f57b8a5514f7d90e61a7b43d1918736223ccbb0379186fd8
[INFO] Entropy: 5.8167 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: CloseServiceHandle (Hint: 1102)
    - Function: CreateServiceA (Hint: 1144)
    - Function: OpenSCManagerA (Hint: 1535)
  Imported DLL: KERNEL32.dll
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: ExitProcess (Hint: 366)
    - Function: GetCurrentProcess (Hint: 552)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleHandleA (Hint: 651)
    - Function: GetProcAddress (Hint: 710)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: GetSystemTimeAsFileTime (Hint: 769)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: OpenProcess (Hint: 1069)
    - Function: QueryFullProcessImageNameA (Hint: 1124)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualAlloc (Hint: 1486)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WriteProcessMemory (Hint: 1576)
    - Function: __C_specific_handler (Hint: 1584)
  Imported DLL: msvcrt.dll
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: _snprintf (Hint: 605)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: memset (Hint: 1033)
    - Function: signal (Hint: 1063)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strstr (Hint: 1095)
    - Function: vfprintf (Hint: 1123)
  Imported DLL: USER32.dll
    - Function: CallNextHookEx (Hint: 31)
    - Function: GetKeyboardState (Hint: 357)
    - Function: SetWindowsHookExA (Hint: 856)
    - Function: ToAscii (Hint: 886)
  Imported DLL: WINHTTP.dll
    - Function: WinHttpCloseHandle (Hint: 9)
    - Function: WinHttpConnect (Hint: 10)
    - Function: WinHttpOpen (Hint: 39)
    - Function: WinHttpOpenRequest (Hint: 40)
    - Function: WinHttpReceiveResponse (Hint: 63)
    - Function: WinHttpSendRequest (Hint: 66)
[END IMPORTS ANALYSIS - 5 DLLs imported]

[INFO] Entry point RVA: 0x5D700
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x9F000
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/keylogger.exe':
  - Section '.text': 651264 bytes at offset 0x600
[+] Success: Extracted 651264 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/keylogger.exe_shellcode.bin'
[INFO] SHA256: 321acc6bbea5c4f86ba74a3dc3c70c650913c1818851c848055751be882225bc
[INFO] Entropy: 6.1858 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2000
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/evasion.exe':
  - Section '.text': 8192 bytes at offset 0x600
[+] Success: Extracted 8192 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/evasion.exe_shellcode.bin'
[INFO] SHA256: b8474e54aa8ed48e726ff7a6b85b72b295f4029a308b68941c64bc46e21e76b4
[INFO] Entropy: 5.8226 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: libstdc++-6.dll
    - Function: _ZNSolsEPFRSoS_E (Hint: 1521)
    - Function: _ZNSolsEm (Hint: 1533)
    - Function: _ZNSt8ios_base4InitC1Ev (Hint: 4392)
    - Function: _ZNSt8ios_base4InitD1Ev (Hint: 4394)
    - Function: _ZSt4cerr (Hint: 4664)
    - Function: _ZSt4cout (Hint: 4666)
    - Function: _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_ (Hint: 4667)
    - Function: _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc (Hint: 4772)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CreateRemoteThread (Hint: 241)
    - Function: CreateToolhelp32Snapshot (Hint: 261)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetLastError (Hint: 630)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: OpenProcess (Hint: 1069)
    - Function: Process32First (Hint: 1097)
    - Function: Process32Next (Hint: 1099)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualAllocEx (Hint: 1487)
    - Function: VirtualFreeEx (Hint: 1490)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForSingleObject (Hint: 1503)
    - Function: WriteProcessMemory (Hint: 1576)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: _stricmp (Hint: 648)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: signal (Hint: 1063)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: vfprintf (Hint: 1123)
[END IMPORTS ANALYSIS - 3 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 5
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0xA00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/modified_wingaypi.exe':
  - Section '.text': 2560 bytes at offset 0x400
[+] Success: Extracted 2560 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/modified_wingaypi.exe_shellcode.bin'
[INFO] SHA256: f25884a93357dbba045e2cd8792db847e138d2502a72695aa9a512aeae44f6e7
[INFO] Entropy: 4.1531 bits/byte

[IMPORTS ANALYSIS]
[END IMPORTS ANALYSIS - 0 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x86 (32-bit)
[INFO] Number of sections: 4
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/rednefeD_swodniW.exe':
  - Section '.text': 512 bytes at offset 0x400
[+] Success: Extracted 512 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/rednefeD_swodniW.exe_shellcode.bin'
[INFO] SHA256: b9434abf0961eb228381f4257296710356df474fb787e4479b0c84558b176bc4
[INFO] Entropy: 2.6678 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: CloseHandle (Hint: 1)
    - Function: GetProcAddress (Hint: 2)
    - Function: LoadLibraryA (Hint: 3)
    - Function: LocalAlloc (Hint: 4)
    - Function: LocalFree (Hint: 5)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x60160
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0xAFE00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/reverse_shell.exe':
  - Section '.text': 720384 bytes at offset 0x600
[+] Success: Extracted 720384 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/reverse_shell.exe_shellcode.bin'
[INFO] SHA256: 40552f4d6861f23835958fe6683081cd524eff1b14f6779db2da0c0b6fd50418
[INFO] Entropy: 6.1521 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0xA400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/cwaytzar_clean.exe':
  - Section '.text': 41984 bytes at offset 0x600
[+] Success: Extracted 41984 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/cwaytzar_clean.exe_shellcode.bin'
[INFO] SHA256: 939aa2f0663b106f6bd09cd9c9c993dee185b64590328710384a217ad2acd753
[INFO] Entropy: 6.2123 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: AdjustTokenPrivileges (Hint: 1032)
    - Function: AllocateAndInitializeSid (Hint: 1033)
    - Function: CheckTokenMembership (Hint: 1096)
    - Function: FreeSid (Hint: 1310)
    - Function: LookupPrivilegeValueA (Hint: 1431)
    - Function: OpenProcessToken (Hint: 1534)
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExW (Hint: 1653)
    - Function: RegSaveKeyW (Hint: 1676)
    - Function: RegSetValueExW (Hint: 1682)
  Imported DLL: dbghelp.dll
    - Function: MiniDumpWriteDump (Hint: 31)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CopyFileA (Hint: 177)
    - Function: CreateFileA (Hint: 204)
    - Function: CreateToolhelp32Snapshot (Hint: 261)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: DeleteFileA (Hint: 285)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetCurrentProcess (Hint: 552)
    - Function: GetFileSize (Hint: 609)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleFileNameA (Hint: 649)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: GetTempPathA (Hint: 781)
    - Function: GetTempPathW (Hint: 782)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDBCSLeadByteEx (Hint: 919)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: MultiByteToWideChar (Hint: 1036)
    - Function: OpenProcess (Hint: 1069)
    - Function: Process32FirstW (Hint: 1098)
    - Function: Process32NextW (Hint: 1100)
    - Function: ReadFile (Hint: 1170)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WideCharToMultiByte (Hint: 1547)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: ___lc_codepage_func (Hint: 64)
    - Function: ___mb_cur_max_func (Hint: 67)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _errno (Hint: 190)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: fwprintf (Hint: 973)
    - Function: _wcsicmp (Hint: 780)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: fputc (Hint: 958)
    - Function: fputwc (Hint: 960)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: getenv (Hint: 982)
    - Function: localeconv (Hint: 1017)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: memset (Hint: 1033)
    - Function: signal (Hint: 1063)
    - Function: strcat (Hint: 1076)
    - Function: strerror (Hint: 1084)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strrchr (Hint: 1093)
    - Function: vfprintf (Hint: 1123)
    - Function: wcslen (Hint: 1149)
    - Function: wcstombs (Hint: 1165)
  Imported DLL: ole32.dll
    - Function: CoCreateInstance (Hint: 31)
    - Function: CoInitializeEx (Hint: 86)
    - Function: CoUninitialize (Hint: 133)
  Imported DLL: SHELL32.dll
    - Function: ShellExecuteA (Hint: 336)
  Imported DLL: USER32.dll
    - Function: CallNextHookEx (Hint: 31)
    - Function: DispatchMessageA (Hint: 185)
    - Function: GetKeyboardState (Hint: 357)
    - Function: GetMessageA (Hint: 380)
    - Function: SetWindowsHookExA (Hint: 856)
    - Function: ToAscii (Hint: 886)
    - Function: TranslateMessage (Hint: 897)
    - Function: UnhookWindowsHookEx (Hint: 901)
  Imported DLL: WINHTTP.dll
    - Function: WinHttpCloseHandle (Hint: 9)
    - Function: WinHttpConnect (Hint: 10)
    - Function: WinHttpCrackUrl (Hint: 22)
    - Function: WinHttpOpen (Hint: 39)
    - Function: WinHttpOpenRequest (Hint: 40)
    - Function: WinHttpReceiveResponse (Hint: 63)
    - Function: WinHttpSendRequest (Hint: 66)
    - Function: WinHttpWriteData (Hint: 81)
[END IMPORTS ANALYSIS - 8 DLLs imported]

[INFO] Entry point RVA: 0x5DCC0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 6
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0xA8C00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/pissnvin.exe':
  - Section '.text': 691200 bytes at offset 0x600
[+] Success: Extracted 691200 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/pissnvin.exe_shellcode.bin'
[INFO] SHA256: e9e9e9ad8b4ab9fb831170493e4d00b9f699475c44b7dc8a427c4ad12e892ae1
[INFO] Entropy: 6.1816 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x777A0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 8
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2BB400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/uhmento_SW.exe':
  - Section '.text': 2864128 bytes at offset 0x600
[+] Success: Extracted 2864128 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/uhmento_SW.exe_shellcode.bin'
[INFO] SHA256: 57ce8aa03bc3e231c9a968c364e78bc854a202ea395c9a14305143652e0723eb
[INFO] Entropy: 6.2094 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WerSetFlags (Hint: 0)
    - Function: WerGetFlags (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: TlsAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: RtlVirtualUnwind (Hint: 0)
    - Function: RtlLookupFunctionEntry (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: RaiseFailFastException (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: LoadLibraryExW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetErrorMode (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetCurrentThreadId (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
    - Function: AddVectoredContinueHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14C0
[INFO] Machine type: x86 (32-bit)
[INFO] Number of sections: 17
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x6E00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/fartbang.exe':
  - Section '.text': 28160 bytes at offset 0x600
[+] Success: Extracted 28160 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/fartbang.exe_shellcode.bin'
[INFO] SHA256: f6997cb3f4d43f242c019e5d815277b5c835d9ef976a1e778cf027c7300c6837
[INFO] Entropy: 6.2187 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: KERNEL32.dll
    - Function: DeleteCriticalSection (Hint: 277)
    - Function: EnterCriticalSection (Hint: 310)
    - Function: FreeLibrary (Hint: 433)
    - Function: GetLastError (Hint: 617)
    - Function: GetModuleHandleA (Hint: 637)
    - Function: GetModuleHandleW (Hint: 640)
    - Function: GetProcAddress (Hint: 694)
    - Function: GetStartupInfoA (Hint: 729)
    - Function: InitializeCriticalSection (Hint: 877)
    - Function: IsDBCSLeadByteEx (Hint: 909)
    - Function: LeaveCriticalSection (Hint: 973)
    - Function: LoadLibraryA (Hint: 977)
    - Function: MultiByteToWideChar (Hint: 1024)
    - Function: SetUnhandledExceptionFilter (Hint: 1370)
    - Function: Sleep (Hint: 1386)
    - Function: TlsGetValue (Hint: 1421)
    - Function: VirtualProtect (Hint: 1469)
    - Function: VirtualQuery (Hint: 1472)
    - Function: WideCharToMultiByte (Hint: 1522)
  Imported DLL: msvcrt.dll
    - Function: __getmainargs (Hint: 58)
    - Function: __initenv (Hint: 59)
    - Function: __lconv_init (Hint: 68)
    - Function: __mb_cur_max (Hint: 69)
    - Function: __p__acmdln (Hint: 76)
    - Function: __p__commode (Hint: 78)
    - Function: __p__fmode (Hint: 83)
    - Function: __set_app_type (Hint: 104)
    - Function: __setusermatherr (Hint: 107)
    - Function: _amsg_exit (Hint: 142)
    - Function: _cexit (Hint: 159)
    - Function: _errno (Hint: 322)
    - Function: _initterm (Hint: 338)
    - Function: _iob (Hint: 342)
    - Function: _lock (Hint: 441)
    - Function: _onexit (Hint: 570)
    - Function: _unlock (Hint: 735)
    - Function: abort (Hint: 922)
    - Function: atoi (Hint: 931)
    - Function: calloc (Hint: 935)
    - Function: exit (Hint: 945)
    - Function: fclose (Hint: 948)
    - Function: fopen (Hint: 959)
    - Function: fprintf (Hint: 962)
    - Function: fputc (Hint: 964)
    - Function: free (Hint: 969)
    - Function: fwrite (Hint: 982)
    - Function: localeconv (Hint: 1023)
    - Function: malloc (Hint: 1027)
    - Function: memcpy (Hint: 1035)
    - Function: puts (Hint: 1047)
    - Function: setlocale (Hint: 1062)
    - Function: signal (Hint: 1064)
    - Function: strchr (Hint: 1076)
    - Function: strerror (Hint: 1082)
    - Function: strlen (Hint: 1084)
    - Function: strncmp (Hint: 1087)
    - Function: system (Hint: 1106)
    - Function: vfprintf (Hint: 1121)
    - Function: wcslen (Hint: 1147)
[END IMPORTS ANALYSIS - 2 DLLs imported]

[INFO] Entry point RVA: 0x5F5C0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x9E400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/2cupsnstring.exe':
  - Section '.text': 648192 bytes at offset 0x600
[+] Success: Extracted 648192 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/2cupsnstring.exe_shellcode.bin'
[INFO] SHA256: 24ade72497eb3b05ce1713a82bd2de846fe0fdfa2208b1828784e9f2993e92c9
[INFO] Entropy: 6.1673 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 4
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/BlackBox-0x00.exe':
  - Section '.text': 512 bytes at offset 0x400
[+] Success: Extracted 512 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/BlackBox-0x00.exe_shellcode.bin'
[INFO] SHA256: 93d37953e65fc60b5e15d9dc574c3b8dbd6983531f768f72afd365ed5890a364
[INFO] Entropy: 4.2100 bits/byte

[IMPORTS ANALYSIS]
[END IMPORTS ANALYSIS - 0 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x4200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/installer_3.exe':
  - Section '.text': 16896 bytes at offset 0x600
[+] Success: Extracted 16896 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/installer_3.exe_shellcode.bin'
[INFO] SHA256: ff5e04ed8f48b6f99f7bf7a16c28521a57a076d0995498142f90f4593a2ae9ce
[INFO] Entropy: 5.6976 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: CryptAcquireContextA (Hint: 1194)
    - Function: CryptCreateHash (Hint: 1197)
    - Function: CryptDecrypt (Hint: 1198)
    - Function: CryptDeriveKey (Hint: 1199)
    - Function: CryptDestroyHash (Hint: 1200)
    - Function: CryptDestroyKey (Hint: 1201)
    - Function: CryptGenRandom (Hint: 1211)
    - Function: CryptHashData (Hint: 1218)
    - Function: CryptReleaseContext (Hint: 1221)
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExA (Hint: 1652)
    - Function: RegQueryValueExA (Hint: 1665)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CreateThread (Hint: 252)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: ExitProcess (Hint: 366)
    - Function: GetLastError (Hint: 630)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDebuggerPresent (Hint: 920)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualAlloc (Hint: 1486)
    - Function: VirtualFree (Hint: 1489)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForSingleObject (Hint: 1503)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: _time64 (Hint: 693)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: memmove (Hint: 1032)
    - Function: rand (Hint: 1051)
    - Function: signal (Hint: 1063)
    - Function: srand (Hint: 1072)
    - Function: strcat_s (Hint: 1077)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strstr (Hint: 1095)
    - Function: vfprintf (Hint: 1123)
  Imported DLL: WININET.dll
    - Function: InternetCloseHandle (Hint: 145)
    - Function: InternetOpenA (Hint: 194)
    - Function: InternetOpenUrlA (Hint: 195)
    - Function: InternetReadFile (Hint: 202)
  Imported DLL: libgcc_s_seh-1.dll
    - Function: _Unwind_Resume (Hint: 15)
  Imported DLL: libstdc++-6.dll
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv (Hint: 731)
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv (Hint: 743)
    - Function: _ZNSaIcEC1Ev (Hint: 1265)
    - Function: _ZNSaIcED1Ev (Hint: 1268)
    - Function: _ZNSaIcED2Ev (Hint: 1269)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv (Hint: 3670)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEy (Hint: 3673)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcRKS3_ (Hint: 3675)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv (Hint: 3685)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEy (Hint: 3686)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsEPcPKcS7_ (Hint: 3689)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendEPKc (Hint: 3711)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc (Hint: 3739)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERyy (Hint: 3769)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_ (Hint: 3775)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev (Hint: 3808)
    - Function: _ZSt17__throw_bad_allocv (Hint: 4624)
    - Function: _ZSt19__throw_logic_errorPKc (Hint: 4638)
    - Function: _ZSt20__throw_length_errorPKc (Hint: 4646)
    - Function: _ZdaPv (Hint: 5611)
    - Function: _ZdlPvy (Hint: 5621)
    - Function: _Znay (Hint: 5623)
    - Function: _Znwy (Hint: 5627)
    - Function: __cxa_begin_catch (Hint: 5637)
    - Function: __cxa_end_catch (Hint: 5642)
    - Function: __cxa_rethrow (Hint: 5653)
    - Function: __gxx_personality_seh0 (Hint: 5670)
[END IMPORTS ANALYSIS - 6 DLLs imported]

[INFO] Entry point RVA: 0x14C0
[INFO] Machine type: x86 (32-bit)
[INFO] Number of sections: 17
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x3A00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/siccysiccy.exe':
  - Section '.text': 14848 bytes at offset 0x600
[+] Success: Extracted 14848 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/siccysiccy.exe_shellcode.bin'
[INFO] SHA256: a63fbf64c016e9186b9bbf73889fb12bf0935a5d0a01741336c6ef996b838c95
[INFO] Entropy: 5.8342 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: RegCloseKey (Hint: 1569)
    - Function: RegOpenKeyExA (Hint: 1617)
    - Function: RegQueryValueExA (Hint: 1630)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 136)
    - Function: CreateToolhelp32Snapshot (Hint: 256)
    - Function: DeleteCriticalSection (Hint: 277)
    - Function: EnterCriticalSection (Hint: 310)
    - Function: FreeLibrary (Hint: 433)
    - Function: GetLastError (Hint: 617)
    - Function: GetModuleHandleA (Hint: 637)
    - Function: GetProcAddress (Hint: 694)
    - Function: GetStartupInfoA (Hint: 729)
    - Function: GetSystemInfo (Hint: 749)
    - Function: GetVersion (Hint: 803)
    - Function: GlobalMemoryStatusEx (Hint: 836)
    - Function: InitializeCriticalSection (Hint: 877)
    - Function: LeaveCriticalSection (Hint: 973)
    - Function: LoadLibraryA (Hint: 977)
    - Function: Process32FirstW (Hint: 1085)
    - Function: Process32NextW (Hint: 1087)
    - Function: SetUnhandledExceptionFilter (Hint: 1370)
    - Function: Sleep (Hint: 1386)
    - Function: TlsGetValue (Hint: 1421)
    - Function: VirtualProtect (Hint: 1469)
    - Function: VirtualQuery (Hint: 1472)
    - Function: WideCharToMultiByte (Hint: 1522)
  Imported DLL: msvcrt.dll
    - Function: __getmainargs (Hint: 58)
    - Function: __initenv (Hint: 59)
    - Function: __lconv_init (Hint: 68)
    - Function: __p__acmdln (Hint: 76)
    - Function: __p__commode (Hint: 78)
    - Function: __p__fmode (Hint: 83)
    - Function: __set_app_type (Hint: 104)
    - Function: __setusermatherr (Hint: 107)
    - Function: _amsg_exit (Hint: 142)
    - Function: _cexit (Hint: 159)
    - Function: _initterm (Hint: 338)
    - Function: _iob (Hint: 342)
    - Function: _onexit (Hint: 570)
    - Function: abort (Hint: 922)
    - Function: calloc (Hint: 935)
    - Function: exit (Hint: 945)
    - Function: fprintf (Hint: 962)
    - Function: free (Hint: 969)
    - Function: fwrite (Hint: 982)
    - Function: malloc (Hint: 1027)
    - Function: memcpy (Hint: 1035)
    - Function: memmove (Hint: 1036)
    - Function: signal (Hint: 1064)
    - Function: strlen (Hint: 1084)
    - Function: strncmp (Hint: 1087)
    - Function: vfprintf (Hint: 1121)
  Imported DLL: USER32.dll
    - Function: CallNextHookEx (Hint: 30)
    - Function: DispatchMessageA (Hint: 184)
    - Function: GetAsyncKeyState (Hint: 282)
    - Function: GetKeyState (Hint: 343)
    - Function: GetMessageA (Hint: 371)
    - Function: MapVirtualKeyA (Hint: 580)
    - Function: SetWindowsHookExA (Hint: 804)
    - Function: TranslateMessage (Hint: 852)
    - Function: UnhookWindowsHookEx (Hint: 856)
  Imported DLL: WINHTTP.dll
    - Function: WinHttpCloseHandle (Hint: 9)
    - Function: WinHttpConnect (Hint: 10)
    - Function: WinHttpOpen (Hint: 39)
    - Function: WinHttpOpenRequest (Hint: 40)
    - Function: WinHttpReceiveResponse (Hint: 50)
    - Function: WinHttpSendRequest (Hint: 53)
  Imported DLL: libgcc_s_dw2-1.dll
    - Function: _Unwind_Resume (Hint: 15)
    - Function: __deregister_frame_info (Hint: 37)
    - Function: __register_frame_info (Hint: 107)
  Imported DLL: libstdc++-6.dll
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13get_allocatorEv (Hint: 772)
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE3endEv (Hint: 784)
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv (Hint: 794)
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5beginEv (Hint: 795)
    - Function: _ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE5c_strEv (Hint: 857)
    - Function: _ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE6lengthEv (Hint: 866)
    - Function: _ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE7_M_dataEv (Hint: 869)
    - Function: _ZNKSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEE3strEv (Hint: 885)
    - Function: _ZNKSt7__cxx1119basic_ostringstreamIcSt11char_traitsIcESaIcEE3strEv (Hint: 893)
    - Function: _ZNSaIcEC1ERKS_ (Hint: 1329)
    - Function: _ZNSaIcEC1Ev (Hint: 1330)
    - Function: _ZNSaIcED1Ev (Hint: 1333)
    - Function: _ZNSaIwEC1Ev (Hint: 1336)
    - Function: _ZNSaIwED1Ev (Hint: 1339)
    - Function: _ZNSaIwED2Ev (Hint: 1340)
    - Function: _ZNSolsEd (Hint: 1592)
    - Function: _ZNSolsEm (Hint: 1598)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendEPKc (Hint: 3729)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendEPKcj (Hint: 3730)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendERKS4_ (Hint: 3731)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6insertEjPKc (Hint: 3748)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7reserveEj (Hint: 3782)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_ (Hint: 3793)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcjRKS3_ (Hint: 3796)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS3_ (Hint: 3797)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev (Hint: 3805)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev (Hint: 3826)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEpLERKS4_ (Hint: 3835)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE10_M_disposeEv (Hint: 3839)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE11_M_capacityEj (Hint: 3842)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_Alloc_hiderC1EPwRKS3_ (Hint: 3844)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_M_local_dataEv (Hint: 3854)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_M_set_lengthEj (Hint: 3855)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE7_M_dataEPw (Hint: 3908)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE9_M_createERjj (Hint: 3938)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEED1Ev (Hint: 3977)
    - Function: _ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEEC1Ev (Hint: 4142)
    - Function: _ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEED1Ev (Hint: 4148)
    - Function: _ZNSt7__cxx1119basic_ostringstreamIcSt11char_traitsIcESaIcEEC1Ev (Hint: 4198)
    - Function: _ZNSt7__cxx1119basic_ostringstreamIcSt11char_traitsIcESaIcEED1Ev (Hint: 4204)
    - Function: _ZSt17__throw_bad_allocv (Hint: 4642)
    - Function: _ZSt19__throw_logic_errorPKc (Hint: 4656)
    - Function: _ZSt20__throw_length_errorPKc (Hint: 4664)
    - Function: _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc (Hint: 4790)
    - Function: _ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE (Hint: 4801)
    - Function: _ZdaPv (Hint: 5617)
    - Function: _ZdlPvj (Hint: 5627)
    - Function: _Znaj (Hint: 5629)
    - Function: _Znwj (Hint: 5633)
    - Function: __cxa_begin_catch (Hint: 5643)
    - Function: __cxa_end_catch (Hint: 5648)
    - Function: __cxa_rethrow (Hint: 5659)
    - Function: __gxx_personality_v0 (Hint: 5676)
[END IMPORTS ANALYSIS - 7 DLLs imported]

[INFO] Entry point RVA: 0x77900
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 10
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2DCA00
[INFO] Entry point is in section '.text'
[DEBUG] Processing section '.stub': RVA=0x6AC000, Raw=0x651400, Size=0x2000
[+] Found 2 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/obfuscated_gumewurm.exe':
  - Section '.text': 3000832 bytes at offset 0x600
  - Section '.stub': 8192 bytes at offset 0x651400
[+] Success: Extracted 3009024 bytes from 2 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/obfuscated_gumewurm.exe_shellcode.bin'
[INFO] SHA256: a01e66614b3a7c8b94850227ff5edff9de7632ddca229237af124f5aa2a3b29d
[INFO] Entropy: 6.2488 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WerSetFlags (Hint: 0)
    - Function: WerGetFlags (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: TlsAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: RtlVirtualUnwind (Hint: 0)
    - Function: RtlLookupFunctionEntry (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: RaiseFailFastException (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: LoadLibraryExW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetErrorMode (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetCurrentThreadId (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
    - Function: AddVectoredContinueHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14C0
[INFO] Machine type: x86 (32-bit)
[INFO] Number of sections: 17
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x7E00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/monogogo_win_exploit.exe':
  - Section '.text': 32256 bytes at offset 0x600
[+] Success: Extracted 32256 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/monogogo_win_exploit.exe_shellcode.bin'
[INFO] SHA256: 23675dc3d3dfee6a3c58968bd77931ac4efc3598ce72d3247236bb531bd45967
[INFO] Entropy: 6.1242 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: CloseServiceHandle (Hint: 1088)
    - Function: OpenSCManagerA (Hint: 1512)
    - Function: OpenServiceA (Hint: 1514)
    - Function: RegCloseKey (Hint: 1569)
    - Function: RegOpenKeyExA (Hint: 1617)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 136)
    - Function: CreateFileA (Hint: 199)
    - Function: CreateThread (Hint: 247)
    - Function: DeleteCriticalSection (Hint: 277)
    - Function: DeleteFileA (Hint: 279)
    - Function: EnterCriticalSection (Hint: 310)
    - Function: FreeLibrary (Hint: 433)
    - Function: GetEnvironmentVariableA (Hint: 576)
    - Function: GetFileAttributesA (Hint: 584)
    - Function: GetLastError (Hint: 617)
    - Function: GetModuleHandleA (Hint: 637)
    - Function: GetModuleHandleW (Hint: 640)
    - Function: GetProcAddress (Hint: 694)
    - Function: GetStartupInfoA (Hint: 729)
    - Function: InitializeCriticalSection (Hint: 877)
    - Function: IsDBCSLeadByteEx (Hint: 909)
    - Function: LeaveCriticalSection (Hint: 973)
    - Function: LoadLibraryA (Hint: 977)
    - Function: MultiByteToWideChar (Hint: 1024)
    - Function: SetUnhandledExceptionFilter (Hint: 1370)
    - Function: Sleep (Hint: 1386)
    - Function: TlsGetValue (Hint: 1421)
    - Function: VirtualProtect (Hint: 1469)
    - Function: VirtualQuery (Hint: 1472)
    - Function: WaitForMultipleObjects (Hint: 1479)
    - Function: WideCharToMultiByte (Hint: 1522)
  Imported DLL: msvcrt.dll
    - Function: __getmainargs (Hint: 58)
    - Function: __initenv (Hint: 59)
    - Function: __lconv_init (Hint: 68)
    - Function: __mb_cur_max (Hint: 69)
    - Function: __p__acmdln (Hint: 76)
    - Function: __p__commode (Hint: 78)
    - Function: __p__fmode (Hint: 83)
    - Function: __set_app_type (Hint: 104)
    - Function: __setusermatherr (Hint: 107)
    - Function: _amsg_exit (Hint: 142)
    - Function: _cexit (Hint: 159)
    - Function: _errno (Hint: 322)
    - Function: _initterm (Hint: 338)
    - Function: _iob (Hint: 342)
    - Function: _lock (Hint: 441)
    - Function: _onexit (Hint: 570)
    - Function: _unlock (Hint: 735)
    - Function: abort (Hint: 922)
    - Function: atoi (Hint: 931)
    - Function: calloc (Hint: 935)
    - Function: exit (Hint: 945)
    - Function: fprintf (Hint: 962)
    - Function: fputc (Hint: 964)
    - Function: free (Hint: 969)
    - Function: fwrite (Hint: 982)
    - Function: localeconv (Hint: 1023)
    - Function: malloc (Hint: 1027)
    - Function: memcpy (Hint: 1035)
    - Function: setlocale (Hint: 1062)
    - Function: signal (Hint: 1064)
    - Function: srand (Hint: 1070)
    - Function: strchr (Hint: 1076)
    - Function: strerror (Hint: 1082)
    - Function: strlen (Hint: 1084)
    - Function: strncmp (Hint: 1087)
    - Function: vfprintf (Hint: 1121)
    - Function: time (Hint: 713)
    - Function: wcslen (Hint: 1147)
  Imported DLL: SETUPAPI.dll
    - Function: SetupDiDestroyDeviceInfoList (Hint: 320)
    - Function: SetupDiGetClassDevsA (Hint: 340)
  Imported DLL: WS2_32.dll
    - Function: WSACleanup (Hint: 27)
    - Function: WSAStartup (Hint: 85)
    - Function: closesocket (Hint: 135)
    - Function: socket (Hint: 167)
[END IMPORTS ANALYSIS - 5 DLLs imported]

[INFO] Entry point RVA: 0x14C0
[INFO] Machine type: x86 (32-bit)
[INFO] Number of sections: 17
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x1C00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/shadowmeld.exe':
  - Section '.text': 7168 bytes at offset 0x600
[+] Success: Extracted 7168 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/shadowmeld.exe_shellcode.bin'
[INFO] SHA256: e1c9c524079866a50fe6f5a527739f938b5b6fbb73efb2f03c5046885166b527
[INFO] Entropy: 5.7894 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: CRYPT32.dll
    - Function: CertCloseStore (Hint: 19)
    - Function: CertEnumCertificatesInStore (Hint: 45)
    - Function: CertGetNameStringA (Hint: 75)
    - Function: CertOpenSystemStoreA (Hint: 91)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 136)
    - Function: CreateProcessW (Hint: 233)
    - Function: CreateSymbolicLinkW (Hint: 245)
    - Function: DeleteCriticalSection (Hint: 277)
    - Function: EnterCriticalSection (Hint: 310)
    - Function: FreeLibrary (Hint: 433)
    - Function: GetLastError (Hint: 617)
    - Function: GetModuleHandleA (Hint: 637)
    - Function: GetProcAddress (Hint: 694)
    - Function: GetStartupInfoA (Hint: 729)
    - Function: InitializeCriticalSection (Hint: 877)
    - Function: IsDebuggerPresent (Hint: 910)
    - Function: LeaveCriticalSection (Hint: 973)
    - Function: LoadLibraryA (Hint: 977)
    - Function: SetUnhandledExceptionFilter (Hint: 1370)
    - Function: Sleep (Hint: 1386)
    - Function: TlsGetValue (Hint: 1421)
    - Function: VirtualProtect (Hint: 1469)
    - Function: VirtualQuery (Hint: 1472)
    - Function: WaitForSingleObject (Hint: 1481)
  Imported DLL: msvcrt.dll
    - Function: __getmainargs (Hint: 58)
    - Function: __initenv (Hint: 59)
    - Function: __lconv_init (Hint: 68)
    - Function: __p__acmdln (Hint: 76)
    - Function: __p__commode (Hint: 78)
    - Function: __p__fmode (Hint: 83)
    - Function: __set_app_type (Hint: 104)
    - Function: __setusermatherr (Hint: 107)
    - Function: _amsg_exit (Hint: 142)
    - Function: _cexit (Hint: 159)
    - Function: _initterm (Hint: 338)
    - Function: _iob (Hint: 342)
    - Function: _onexit (Hint: 570)
    - Function: abort (Hint: 922)
    - Function: calloc (Hint: 935)
    - Function: exit (Hint: 945)
    - Function: fprintf (Hint: 962)
    - Function: free (Hint: 969)
    - Function: fwrite (Hint: 982)
    - Function: malloc (Hint: 1027)
    - Function: memcpy (Hint: 1035)
    - Function: signal (Hint: 1064)
    - Function: strlen (Hint: 1084)
    - Function: strncmp (Hint: 1087)
    - Function: vfprintf (Hint: 1121)
  Imported DLL: WS2_32.dll
    - Function: WSACleanup (Hint: 27)
    - Function: WSAStartup (Hint: 85)
    - Function: closesocket (Hint: 135)
    - Function: htons (Hint: 151)
    - Function: inet_addr (Hint: 152)
    - Function: sendto (Hint: 164)
    - Function: socket (Hint: 167)
  Imported DLL: libgcc_s_dw2-1.dll
    - Function: _Unwind_Resume (Hint: 15)
    - Function: __deregister_frame_info (Hint: 37)
    - Function: __register_frame_info (Hint: 107)
  Imported DLL: libstdc++-6.dll
    - Function: _ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE5c_strEv (Hint: 857)
    - Function: _ZNSaIwEC1Ev (Hint: 1336)
    - Function: _ZNSaIwED1Ev (Hint: 1339)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1EPKwRKS3_ (Hint: 3946)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEED1Ev (Hint: 3977)
    - Function: _ZNSt8ios_base4InitC1Ev (Hint: 4410)
    - Function: _ZNSt8ios_base4InitD1Ev (Hint: 4412)
    - Function: _ZSt4cerr (Hint: 4682)
    - Function: _ZSt4cout (Hint: 4684)
    - Function: _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc (Hint: 4790)
    - Function: __gxx_personality_v0 (Hint: 5676)
[END IMPORTS ANALYSIS - 6 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/compromise.exe':
  - Section '.text': 8704 bytes at offset 0x600
[+] Success: Extracted 8704 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/compromise.exe_shellcode.bin'
[INFO] SHA256: 4c7cec408533abfd3fc438b5522627867acbce7027be6c1dca00460deb33c6e5
[INFO] Entropy: 5.9143 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: AdjustTokenPrivileges (Hint: 1032)
    - Function: CryptAcquireContextA (Hint: 1194)
    - Function: CryptCreateHash (Hint: 1197)
    - Function: CryptDecrypt (Hint: 1198)
    - Function: CryptDeriveKey (Hint: 1199)
    - Function: CryptDestroyHash (Hint: 1200)
    - Function: CryptDestroyKey (Hint: 1201)
    - Function: CryptGenRandom (Hint: 1211)
    - Function: CryptHashData (Hint: 1218)
    - Function: CryptReleaseContext (Hint: 1221)
    - Function: LookupPrivilegeValueA (Hint: 1431)
    - Function: OpenProcessToken (Hint: 1534)
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExA (Hint: 1652)
    - Function: RegQueryValueExA (Hint: 1665)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CreateThread (Hint: 252)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetCurrentProcess (Hint: 552)
    - Function: GetLastError (Hint: 630)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualAlloc (Hint: 1486)
    - Function: VirtualFree (Hint: 1489)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForSingleObject (Hint: 1503)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: _time64 (Hint: 693)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: rand (Hint: 1051)
    - Function: signal (Hint: 1063)
    - Function: srand (Hint: 1072)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strstr (Hint: 1095)
    - Function: vfprintf (Hint: 1123)
  Imported DLL: libstdc++-6.dll
    - Function: _ZdaPv (Hint: 5611)
    - Function: _Znay (Hint: 5623)
[END IMPORTS ANALYSIS - 4 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 4
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/blud_thinner.exe':
  - Section '.text': 1024 bytes at offset 0x400
[+] Success: Extracted 1024 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/blud_thinner.exe_shellcode.bin'
[INFO] SHA256: fe6c8151c51d80dc504442e24940f17b1455b91c4d9ba966298c8aea1b4a1bde
[INFO] Entropy: 3.1065 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: CloseServiceHandle (Hint: 1102)
    - Function: ControlService (Hint: 1107)
    - Function: OpenSCManagerW (Hint: 1536)
    - Function: OpenServiceW (Hint: 1538)
    - Function: QueryServiceStatus (Hint: 1593)
  Imported DLL: KERNEL32.dll
    - Function: ExitProcess (Hint: 366)
    - Function: GetCurrentProcessId (Hint: 553)
    - Function: GetProcessHeap (Hint: 716)
    - Function: GetTickCount64 (Hint: 800)
    - Function: QueryPerformanceCounter (Hint: 1131)
  Imported DLL: ntdll.dll
    - Function: RtlGetVersion (Hint: 1145)
[END IMPORTS ANALYSIS - 3 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 10
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x340000
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/rustyklog.exe':
  - Section '.text': 3407872 bytes at offset 0x400
[+] Success: Extracted 3407872 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/rustyklog.exe_shellcode.bin'
[INFO] SHA256: 60a0434610a4c462fcf294259dec087330aca240f24214d481e9914a6acd4a78
[INFO] Entropy: 6.2957 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: KERNEL32.dll
    - Function: AddVectoredExceptionHandler (Hint: 17)
    - Function: CancelIo (Hint: 52)
    - Function: CancelIoEx (Hint: 53)
    - Function: CloseHandle (Hint: 69)
    - Function: CompareStringOrdinal (Hint: 85)
    - Function: ConnectNamedPipe (Hint: 87)
    - Function: CopyFileExW (Hint: 97)
    - Function: CreateDirectoryW (Hint: 111)
    - Function: CreateEventW (Hint: 116)
    - Function: CreateFileMappingA (Hint: 121)
    - Function: CreateFileW (Hint: 128)
    - Function: CreateHardLinkW (Hint: 132)
    - Function: CreateIoCompletionPort (Hint: 133)
    - Function: CreatePipe (Hint: 146)
    - Function: CreateProcessW (Hint: 150)
    - Function: CreateSymbolicLinkW (Hint: 160)
    - Function: CreateThread (Hint: 162)
    - Function: CreateToolhelp32Snapshot (Hint: 171)
    - Function: CreateWaitableTimerExW (Hint: 176)
    - Function: DeleteFileW (Hint: 197)
    - Function: DeleteProcThreadAttributeList (Hint: 198)
    - Function: DeviceIoControl (Hint: 208)
    - Function: DisconnectNamedPipe (Hint: 213)
    - Function: DuplicateHandle (Hint: 219)
    - Function: ExitProcess (Hint: 272)
    - Function: FileTimeToSystemTime (Hint: 281)
    - Function: FindClose (Hint: 290)
    - Function: FindFirstFileExW (Hint: 296)
    - Function: FindNextFileW (Hint: 313)
    - Function: FlushFileBuffers (Hint: 332)
    - Function: FormatMessageW (Hint: 340)
    - Function: FreeEnvironmentStringsW (Hint: 343)
    - Function: GetCommandLineW (Hint: 378)
    - Function: GetConsoleMode (Hint: 402)
    - Function: GetConsoleOutputCP (Hint: 405)
    - Function: GetConsoleScreenBufferInfo (Hint: 407)
    - Function: GetCurrentDirectoryW (Hint: 421)
    - Function: GetCurrentProcess (Hint: 427)
    - Function: GetCurrentProcessId (Hint: 428)
    - Function: GetCurrentThread (Hint: 431)
    - Function: GetCurrentThreadId (Hint: 432)
    - Function: GetEnvironmentStringsW (Hint: 455)
    - Function: GetEnvironmentVariableW (Hint: 457)
    - Function: GetExitCodeProcess (Hint: 460)
    - Function: GetFileAttributesW (Hint: 467)
    - Function: GetFileInformationByHandle (Hint: 469)
    - Function: GetFileInformationByHandleEx (Hint: 470)
    - Function: GetFileSizeEx (Hint: 474)
    - Function: GetFileType (Hint: 476)
    - Function: GetFinalPathNameByHandleW (Hint: 478)
    - Function: GetFullPathNameW (Hint: 487)
    - Function: GetLastError (Hint: 494)
    - Function: GetModuleFileNameW (Hint: 513)
    - Function: GetModuleHandleA (Hint: 514)
    - Function: GetModuleHandleW (Hint: 517)
    - Function: GetNamedPipeInfo (Hint: 527)
    - Function: GetOverlappedResult (Hint: 548)
    - Function: GetProcAddress (Hint: 570)
    - Function: GetProcessHeap (Hint: 576)
    - Function: GetProcessId (Hint: 578)
    - Function: GetQueuedCompletionStatusEx (Hint: 599)
    - Function: GetStartupInfoA (Hint: 603)
    - Function: GetStdHandle (Hint: 606)
    - Function: GetSystemDirectoryW (Hint: 620)
    - Function: GetSystemInfo (Hint: 623)
    - Function: GetSystemTimePreciseAsFileTime (Hint: 630)
    - Function: GetTempPathW (Hint: 642)
    - Function: GetWindowsDirectoryW (Hint: 689)
    - Function: HeapAlloc (Hint: 720)
    - Function: HeapFree (Hint: 724)
    - Function: HeapReAlloc (Hint: 727)
    - Function: InitOnceBeginInitialize (Hint: 735)
    - Function: InitOnceComplete (Hint: 736)
    - Function: InitializeProcThreadAttributeList (Hint: 745)
    - Function: LocalFree (Hint: 831)
    - Function: LockFileEx (Hint: 841)
    - Function: MapViewOfFile (Hint: 845)
    - Function: Module32FirstW (Hint: 850)
    - Function: Module32NextW (Hint: 852)
    - Function: MoveFileExW (Hint: 855)
    - Function: MultiByteToWideChar (Hint: 862)
    - Function: PostQueuedCompletionStatus (Hint: 902)
    - Function: QueryPerformanceCounter (Hint: 940)
    - Function: QueryPerformanceFrequency (Hint: 941)
    - Function: ReadConsoleW (Hint: 963)
    - Function: ReadFile (Hint: 966)
    - Function: ReadFileEx (Hint: 967)
    - Function: RemoveDirectoryW (Hint: 989)
    - Function: RtlCaptureContext (Hint: 1010)
    - Function: RtlLookupFunctionEntry (Hint: 1017)
    - Function: RtlVirtualUnwind (Hint: 1024)
    - Function: SetConsoleMode (Hint: 1051)
    - Function: SetConsoleTextAttribute (Hint: 1055)
    - Function: SetCurrentDirectoryW (Hint: 1062)
    - Function: SetEnvironmentVariableW (Hint: 1073)
    - Function: SetFileAttributesW (Hint: 1082)
    - Function: SetFileCompletionNotificationModes (Hint: 1084)
    - Function: SetFileInformationByHandle (Hint: 1085)
    - Function: SetFilePointerEx (Hint: 1088)
    - Function: SetFileTime (Hint: 1091)
    - Function: SetHandleInformation (Hint: 1098)
    - Function: SetLastError (Hint: 1101)
    - Function: SetThreadStackGuarantee (Hint: 1147)
    - Function: SetUnhandledExceptionFilter (Hint: 1159)
    - Function: SetWaitableTimer (Hint: 1166)
    - Function: Sleep (Hint: 1172)
    - Function: SleepEx (Hint: 1175)
    - Function: SwitchToThread (Hint: 1180)
    - Function: TerminateProcess (Hint: 1185)
    - Function: TlsAlloc (Hint: 1189)
    - Function: TlsFree (Hint: 1190)
    - Function: TlsGetValue (Hint: 1191)
    - Function: TlsSetValue (Hint: 1192)
    - Function: UnlockFile (Hint: 1204)
    - Function: UnmapViewOfFile (Hint: 1206)
    - Function: UpdateProcThreadAttribute (Hint: 1214)
    - Function: WaitForMultipleObjects (Hint: 1238)
    - Function: WaitForSingleObject (Hint: 1240)
    - Function: WideCharToMultiByte (Hint: 1267)
    - Function: WriteConsoleW (Hint: 1284)
    - Function: WriteFile (Hint: 1285)
    - Function: WriteFileEx (Hint: 1286)
  Imported DLL: USER32.dll
    - Function: CallNextHookEx (Hint: 26)
    - Function: DispatchMessageW (Hint: 159)
    - Function: GetMessageW (Hint: 331)
    - Function: SetWindowsHookExW (Hint: 692)
    - Function: TranslateMessage (Hint: 728)
  Imported DLL: advapi32.dll
    - Function: CryptAcquireContextW (Hint: 0)
    - Function: CryptDestroyKey (Hint: 0)
    - Function: CryptImportKey (Hint: 0)
    - Function: CryptReleaseContext (Hint: 0)
    - Function: RegCloseKey (Hint: 0)
    - Function: RegEnumKeyExW (Hint: 0)
    - Function: RegEnumValueW (Hint: 0)
    - Function: RegOpenKeyExW (Hint: 0)
    - Function: RegQueryInfoKeyW (Hint: 0)
    - Function: RegQueryValueExW (Hint: 0)
    - Function: SystemFunction036 (Hint: 0)
  Imported DLL: bcrypt.dll
    - Function: BCryptGenRandom (Hint: 0)
  Imported DLL: crypt32.dll
    - Function: CertAddCertificateContextToStore (Hint: 0)
    - Function: CertAddEncodedCTLToStore (Hint: 0)
    - Function: CertAddEncodedCertificateToStore (Hint: 0)
    - Function: CertCloseStore (Hint: 0)
    - Function: CertCreateCTLEntryFromCertificateContextProperties (Hint: 0)
    - Function: CertCreateCertificateContext (Hint: 0)
    - Function: CertDeleteCertificateFromStore (Hint: 0)
    - Function: CertDuplicateCertificateChain (Hint: 0)
    - Function: CertDuplicateCertificateContext (Hint: 0)
    - Function: CertDuplicateStore (Hint: 0)
    - Function: CertEnumCertificatesInStore (Hint: 0)
    - Function: CertFreeCTLContext (Hint: 0)
    - Function: CertFreeCertificateChain (Hint: 0)
    - Function: CertFreeCertificateContext (Hint: 0)
    - Function: CertGetCertificateChain (Hint: 0)
    - Function: CertGetCertificateContextProperty (Hint: 0)
    - Function: CertGetEnhancedKeyUsage (Hint: 0)
    - Function: CertOpenStore (Hint: 0)
    - Function: CertSetCertificateContextProperty (Hint: 0)
    - Function: CertVerifyCertificateChainPolicy (Hint: 0)
    - Function: CertVerifyTimeValidity (Hint: 0)
    - Function: CryptAcquireCertificatePrivateKey (Hint: 0)
    - Function: CryptBinaryToStringA (Hint: 0)
    - Function: CryptDecodeObjectEx (Hint: 0)
    - Function: CryptEncodeObjectEx (Hint: 0)
    - Function: CryptHashCertificate (Hint: 0)
    - Function: CryptMsgEncodeAndSignCTL (Hint: 0)
    - Function: CryptStringToBinaryA (Hint: 0)
    - Function: PFXExportCertStore (Hint: 0)
    - Function: PFXImportCertStore (Hint: 0)
  Imported DLL: ncrypt.dll
    - Function: NCryptFreeObject (Hint: 0)
  Imported DLL: ntdll.dll
    - Function: NtCancelIoFileEx (Hint: 0)
    - Function: NtCreateFile (Hint: 0)
    - Function: NtDeviceIoControlFile (Hint: 0)
    - Function: NtOpenFile (Hint: 0)
    - Function: NtReadFile (Hint: 0)
    - Function: NtWriteFile (Hint: 0)
    - Function: RtlNtStatusToDosError (Hint: 0)
  Imported DLL: secur32.dll
    - Function: AcceptSecurityContext (Hint: 0)
    - Function: AcquireCredentialsHandleA (Hint: 0)
    - Function: ApplyControlToken (Hint: 0)
    - Function: DecryptMessage (Hint: 0)
    - Function: DeleteSecurityContext (Hint: 0)
    - Function: EncryptMessage (Hint: 0)
    - Function: FreeContextBuffer (Hint: 0)
    - Function: FreeCredentialsHandle (Hint: 0)
    - Function: InitializeSecurityContextW (Hint: 0)
    - Function: QueryContextAttributesW (Hint: 0)
  Imported DLL: userenv.dll
    - Function: GetUserProfileDirectoryW (Hint: 0)
  Imported DLL: ws2_32.dll
    - Function: WSACleanup (Hint: 0)
    - Function: WSADuplicateSocketW (Hint: 0)
    - Function: WSAGetLastError (Hint: 0)
    - Function: WSAIoctl (Hint: 0)
    - Function: WSAPoll (Hint: 0)
    - Function: WSARecv (Hint: 0)
    - Function: WSARecvFrom (Hint: 0)
    - Function: WSASend (Hint: 0)
    - Function: WSASendMsg (Hint: 0)
    - Function: WSASendTo (Hint: 0)
    - Function: WSASocketW (Hint: 0)
    - Function: WSAStartup (Hint: 0)
    - Function: accept (Hint: 0)
    - Function: bind (Hint: 0)
    - Function: closesocket (Hint: 0)
    - Function: connect (Hint: 0)
    - Function: freeaddrinfo (Hint: 0)
    - Function: getaddrinfo (Hint: 0)
    - Function: getpeername (Hint: 0)
    - Function: getsockname (Hint: 0)
    - Function: getsockopt (Hint: 0)
    - Function: ioctlsocket (Hint: 0)
    - Function: listen (Hint: 0)
    - Function: recv (Hint: 0)
    - Function: recvfrom (Hint: 0)
    - Function: select (Hint: 0)
    - Function: send (Hint: 0)
    - Function: sendto (Hint: 0)
    - Function: setsockopt (Hint: 0)
    - Function: shutdown (Hint: 0)
    - Function: socket (Hint: 0)
  Imported DLL: api-ms-win-core-synch-l1-2-0.dll
    - Function: WaitOnAddress (Hint: 3)
    - Function: WakeByAddressAll (Hint: 1)
    - Function: WakeByAddressSingle (Hint: 2)
  Imported DLL: bcryptprimitives.dll
    - Function: ProcessPrng (Hint: 1)
  Imported DLL: KERNEL32.dll
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: RaiseException (Hint: 1153)
    - Function: RtlUnwindEx (Hint: 1236)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: __C_specific_handler (Hint: 1584)
  Imported DLL: msvcrt.dll
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _fpreset (Hint: 223)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcmp (Hint: 1030)
    - Function: memcpy (Hint: 1031)
    - Function: memmove (Hint: 1032)
    - Function: memset (Hint: 1033)
    - Function: signal (Hint: 1063)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: vfprintf (Hint: 1123)
  Imported DLL: ntdll.dll
    - Function: NtCreateNamedPipeFile (Hint: 324)
[END IMPORTS ANALYSIS - 15 DLLs imported]

[INFO] Entry point RVA: 0x6D5E0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 15
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x234A00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/cheapsuit.exe':
  - Section '.text': 2312704 bytes at offset 0x600
[+] Success: Extracted 2312704 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/cheapsuit.exe_shellcode.bin'
[INFO] SHA256: 1e7e39b9cddb1dfedf843417896b4874435000e92c81dbfaa447f703c59edb4a
[INFO] Entropy: 6.2231 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WerSetFlags (Hint: 0)
    - Function: WerGetFlags (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: TlsAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: RtlVirtualUnwind (Hint: 0)
    - Function: RtlLookupFunctionEntry (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: RaiseFailFastException (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: LoadLibraryExW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetErrorMode (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetCurrentThreadId (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
    - Function: AddVectoredContinueHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/SolaraBootstrapper.exe':
  - Section '.text': 8704 bytes at offset 0x600
[+] Success: Extracted 8704 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/SolaraBootstrapper.exe_shellcode.bin'
[INFO] SHA256: aef1fed4b9dc19b8f57b8a5514f7d90e61a7b43d1918736223ccbb0379186fd8
[INFO] Entropy: 5.8167 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: CloseServiceHandle (Hint: 1102)
    - Function: CreateServiceA (Hint: 1144)
    - Function: OpenSCManagerA (Hint: 1535)
  Imported DLL: KERNEL32.dll
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: ExitProcess (Hint: 366)
    - Function: GetCurrentProcess (Hint: 552)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleHandleA (Hint: 651)
    - Function: GetProcAddress (Hint: 710)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: GetSystemTimeAsFileTime (Hint: 769)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: OpenProcess (Hint: 1069)
    - Function: QueryFullProcessImageNameA (Hint: 1124)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualAlloc (Hint: 1486)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WriteProcessMemory (Hint: 1576)
    - Function: __C_specific_handler (Hint: 1584)
  Imported DLL: msvcrt.dll
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: _snprintf (Hint: 605)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: memset (Hint: 1033)
    - Function: signal (Hint: 1063)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strstr (Hint: 1095)
    - Function: vfprintf (Hint: 1123)
  Imported DLL: USER32.dll
    - Function: CallNextHookEx (Hint: 31)
    - Function: GetKeyboardState (Hint: 357)
    - Function: SetWindowsHookExA (Hint: 856)
    - Function: ToAscii (Hint: 886)
  Imported DLL: WINHTTP.dll
    - Function: WinHttpCloseHandle (Hint: 9)
    - Function: WinHttpConnect (Hint: 10)
    - Function: WinHttpOpen (Hint: 39)
    - Function: WinHttpOpenRequest (Hint: 40)
    - Function: WinHttpReceiveResponse (Hint: 63)
    - Function: WinHttpSendRequest (Hint: 66)
[END IMPORTS ANALYSIS - 5 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 5
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0xA00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/packed_wingaypi.exe':
  - Section '.text': 2560 bytes at offset 0x400
[+] Success: Extracted 2560 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/packed_wingaypi.exe_shellcode.bin'
[INFO] SHA256: f25884a93357dbba045e2cd8792db847e138d2502a72695aa9a512aeae44f6e7
[INFO] Entropy: 4.1531 bits/byte

[IMPORTS ANALYSIS]
[END IMPORTS ANALYSIS - 0 DLLs imported]

[INFO] Entry point RVA: 0x5DFC0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x92E00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/loader_1_multiformat.exe':
  - Section '.text': 601600 bytes at offset 0x600
[+] Success: Extracted 601600 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/loader_1_multiformat.exe_shellcode.bin'
[INFO] SHA256: 851a8d835dbb1883b74ec5b36df3d4395e86110c17677b038c5b1ac4a33afe38
[INFO] Entropy: 6.1755 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x4800
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/logger_2.exe':
  - Section '.text': 18432 bytes at offset 0x600
[+] Success: Extracted 18432 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/logger_2.exe_shellcode.bin'
[INFO] SHA256: baa60309f0d521ea163d8718385dad36db8a9d0ff1eebbfee436932a6eae6239
[INFO] Entropy: 5.7424 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: GDI32.dll
    - Function: BitBlt (Hint: 20)
    - Function: CreateCompatibleBitmap (Hint: 49)
    - Function: CreateCompatibleDC (Hint: 50)
    - Function: DeleteDC (Hint: 385)
    - Function: SelectObject (Hint: 870)
  Imported DLL: gdiplus.dll
    - Function: GdipAlloc (Hint: 34)
    - Function: GdipCloneImage (Hint: 55)
    - Function: GdipCreateBitmapFromHBITMAP (Hint: 78)
    - Function: GdipDisposeImage (Hint: 153)
    - Function: GdipFree (Hint: 238)
    - Function: GdipGetImageEncoders (Hint: 287)
    - Function: GdipGetImageEncodersSize (Hint: 288)
    - Function: GdipSaveImageToStream (Hint: 498)
    - Function: GdiplusShutdown (Hint: 629)
    - Function: GdiplusStartup (Hint: 630)
  Imported DLL: KERNEL32.dll
    - Function: CreateThread (Hint: 252)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleHandleA (Hint: 651)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: GlobalLock (Hint: 850)
    - Function: GlobalSize (Hint: 854)
    - Function: GlobalUnlock (Hint: 857)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: memmove (Hint: 1032)
    - Function: signal (Hint: 1063)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: vfprintf (Hint: 1123)
    - Function: wcscmp (Hint: 1143)
  Imported DLL: ole32.dll
    - Function: CreateStreamOnHGlobal (Hint: 160)
    - Function: GetHGlobalFromStream (Hint: 179)
  Imported DLL: USER32.dll
    - Function: AddClipboardFormatListener (Hint: 2)
    - Function: CallNextHookEx (Hint: 31)
    - Function: CloseClipboard (Hint: 78)
    - Function: CreateWindowExA (Hint: 115)
    - Function: DefWindowProcA (Hint: 164)
    - Function: DispatchMessageA (Hint: 185)
    - Function: GetClipboardData (Hint: 307)
    - Function: GetDC (Hint: 319)
    - Function: GetMessageA (Hint: 380)
    - Function: GetSystemMetrics (Hint: 440)
    - Function: OpenClipboard (Hint: 637)
    - Function: PostQuitMessage (Hint: 656)
    - Function: RegisterClassExA (Hint: 697)
    - Function: ReleaseDC (Hint: 729)
    - Function: RemoveClipboardFormatListener (Hint: 731)
    - Function: SetTimer (Hint: 832)
    - Function: SetWindowsHookExA (Hint: 856)
    - Function: TranslateMessage (Hint: 897)
    - Function: UnhookWindowsHookEx (Hint: 901)
  Imported DLL: libgcc_s_seh-1.dll
    - Function: _Unwind_Resume (Hint: 15)
  Imported DLL: libstdc++-6.dll
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6substrEyy (Hint: 742)
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv (Hint: 743)
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEy (Hint: 756)
    - Function: _ZNKSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEE3strEv (Hint: 820)
    - Function: _ZNSaIcEC1Ev (Hint: 1265)
    - Function: _ZNSaIcED1Ev (Hint: 1268)
    - Function: _ZNSaIcED2Ev (Hint: 1269)
    - Function: _ZNSolsEPFRSoS_E (Hint: 1521)
    - Function: _ZNSolsEm (Hint: 1533)
    - Function: _ZNSt14basic_ofstreamIcSt11char_traitsIcEE5closeEv (Hint: 2486)
    - Function: _ZNSt14basic_ofstreamIcSt11char_traitsIcEE7is_openEv (Hint: 2487)
    - Function: _ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode (Hint: 2489)
    - Function: _ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev (Hint: 2501)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv (Hint: 3670)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEy (Hint: 3673)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcRKS3_ (Hint: 3675)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructEyc (Hint: 3678)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv (Hint: 3685)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEy (Hint: 3686)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsEPcPKcS7_ (Hint: 3689)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc (Hint: 3739)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERyy (Hint: 3769)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev (Hint: 3786)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev (Hint: 3808)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_ (Hint: 3810)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEpLEc (Hint: 3819)
    - Function: _ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEEC1Ev (Hint: 4124)
    - Function: _ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEED1Ev (Hint: 4130)
    - Function: _ZNSt8ios_base4InitC1Ev (Hint: 4392)
    - Function: _ZNSt8ios_base4InitD1Ev (Hint: 4394)
    - Function: _ZSt17__throw_bad_allocv (Hint: 4624)
    - Function: _ZSt19__throw_logic_errorPKc (Hint: 4638)
    - Function: _ZSt20__throw_length_errorPKc (Hint: 4646)
    - Function: _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_ (Hint: 4667)
    - Function: _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc (Hint: 4772)
    - Function: _ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE (Hint: 4783)
    - Function: _ZTVN10__cxxabiv117__class_type_infoE (Hint: 5369)
    - Function: _ZTVN10__cxxabiv120__si_class_type_infoE (Hint: 5373)
    - Function: _ZdlPvy (Hint: 5621)
    - Function: _Znwy (Hint: 5627)
    - Function: __cxa_begin_catch (Hint: 5637)
    - Function: __cxa_end_catch (Hint: 5642)
    - Function: __cxa_rethrow (Hint: 5653)
    - Function: __gxx_personality_seh0 (Hint: 5670)
[END IMPORTS ANALYSIS - 8 DLLs imported]

[INFO] Entry point RVA: 0x14D0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 10
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x2CA800
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/obfuscated_rustbuckit.exe':
  - Section '.text': 2926592 bytes at offset 0x400
[+] Success: Extracted 2926592 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/obfuscated_rustbuckit.exe_shellcode.bin'
[INFO] SHA256: 47622e95a89a2d5d3364748ff3713459bf6511e90b53d8e42a80ce34c512a3a2
[INFO] Entropy: 6.3155 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: advapi32.dll
    - Function: AdjustTokenPrivileges (Hint: 26)
    - Function: CryptAcquireContextW (Hint: 95)
    - Function: CryptDestroyKey (Hint: 101)
    - Function: CryptImportKey (Hint: 120)
    - Function: CryptReleaseContext (Hint: 121)
    - Function: LookupPrivilegeValueA (Hint: 202)
  Imported DLL: crypt32.dll
    - Function: CertAddCertificateContextToStore (Hint: 5)
    - Function: CertAddEncodedCTLToStore (Hint: 8)
    - Function: CertAddEncodedCertificateToStore (Hint: 9)
    - Function: CertCloseStore (Hint: 19)
    - Function: CertCreateCTLEntryFromCertificateContextProperties (Hint: 27)
    - Function: CertCreateCertificateContext (Hint: 29)
    - Function: CertDeleteCertificateFromStore (Hint: 34)
    - Function: CertDuplicateCertificateChain (Hint: 37)
    - Function: CertDuplicateCertificateContext (Hint: 38)
    - Function: CertDuplicateStore (Hint: 39)
    - Function: CertEnumCertificatesInStore (Hint: 45)
    - Function: CertFreeCTLContext (Hint: 61)
    - Function: CertFreeCertificateChain (Hint: 62)
    - Function: CertFreeCertificateContext (Hint: 65)
    - Function: CertGetCertificateChain (Hint: 70)
    - Function: CertGetCertificateContextProperty (Hint: 71)
    - Function: CertGetEnhancedKeyUsage (Hint: 72)
    - Function: CertOpenStore (Hint: 90)
    - Function: CertSetCertificateContextProperty (Hint: 109)
    - Function: CertVerifyCertificateChainPolicy (Hint: 119)
    - Function: CertVerifyTimeValidity (Hint: 122)
    - Function: CryptAcquireCertificatePrivateKey (Hint: 124)
    - Function: CryptBinaryToStringA (Hint: 125)
    - Function: CryptDecodeObjectEx (Hint: 132)
    - Function: CryptEncodeObjectEx (Hint: 136)
    - Function: CryptHashCertificate (Hint: 158)
    - Function: CryptMsgEncodeAndSignCTL (Hint: 179)
    - Function: CryptStringToBinaryA (Hint: 202)
    - Function: PFXExportCertStore (Hint: 219)
    - Function: PFXImportCertStore (Hint: 221)
  Imported DLL: kernel32.dll
    - Function: CancelIoEx (Hint: 21)
    - Function: CloseHandle (Hint: 27)
    - Function: ConnectNamedPipe (Hint: 29)
    - Function: CreateFileW (Hint: 53)
    - Function: CreateIoCompletionPort (Hint: 58)
    - Function: CreateNamedPipeW (Hint: 61)
    - Function: DisconnectNamedPipe (Hint: 79)
    - Function: GetLastError (Hint: 193)
    - Function: GetModuleHandleA (Hint: 207)
    - Function: GetModuleHandleW (Hint: 210)
    - Function: GetNamedPipeInfo (Hint: 217)
    - Function: GetOverlappedResult (Hint: 221)
    - Function: GetProcAddress (Hint: 234)
    - Function: GetQueuedCompletionStatusEx (Hint: 247)
    - Function: LocalFree (Hint: 353)
    - Function: PostQueuedCompletionStatus (Hint: 386)
    - Function: ReadFile (Hint: 400)
    - Function: SetFileCompletionNotificationModes (Hint: 437)
    - Function: SetHandleInformation (Hint: 451)
    - Function: VirtualAllocEx (Hint: 482)
    - Function: VirtualFreeEx (Hint: 485)
    - Function: VirtualQueryEx (Hint: 490)
    - Function: WriteFile (Hint: 497)
  Imported DLL: ncrypt.dll
    - Function: NCryptFreeObject (Hint: 17)
  Imported DLL: ntdll.dll
    - Function: NtCancelIoFileEx (Hint: 9)
    - Function: NtCreateFile (Hint: 13)
    - Function: NtDeviceIoControlFile (Hint: 18)
    - Function: RtlNtStatusToDosError (Hint: 157)
  Imported DLL: secur32.dll
    - Function: AcceptSecurityContext (Hint: 1)
    - Function: AcquireCredentialsHandleA (Hint: 2)
    - Function: ApplyControlToken (Hint: 8)
    - Function: DecryptMessage (Hint: 14)
    - Function: DeleteSecurityContext (Hint: 15)
    - Function: EncryptMessage (Hint: 18)
    - Function: FreeContextBuffer (Hint: 22)
    - Function: FreeCredentialsHandle (Hint: 23)
    - Function: InitializeSecurityContextW (Hint: 35)
    - Function: QueryContextAttributesW (Hint: 49)
  Imported DLL: ws2_32.dll
    - Function: WSADuplicateSocketW (Hint: 35)
    - Function: WSAGetLastError (Hint: 42)
    - Function: WSAIoctl (Hint: 53)
    - Function: WSAPoll (Hint: 60)
    - Function: WSARecv (Hint: 63)
    - Function: WSARecvFrom (Hint: 65)
    - Function: WSASend (Hint: 68)
    - Function: WSASendMsg (Hint: 70)
    - Function: WSASendTo (Hint: 71)
    - Function: WSASocketW (Hint: 76)
    - Function: accept (Hint: 112)
    - Function: bind (Hint: 113)
    - Function: closesocket (Hint: 114)
    - Function: connect (Hint: 115)
    - Function: getpeername (Hint: 122)
    - Function: getsockname (Hint: 127)
    - Function: getsockopt (Hint: 128)
    - Function: ioctlsocket (Hint: 135)
    - Function: listen (Hint: 136)
    - Function: recv (Hint: 139)
    - Function: recvfrom (Hint: 140)
    - Function: send (Hint: 142)
    - Function: sendto (Hint: 143)
    - Function: setsockopt (Hint: 144)
    - Function: shutdown (Hint: 145)
    - Function: socket (Hint: 146)
  Imported DLL: KERNEL32.dll
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: RaiseException (Hint: 1153)
    - Function: RtlUnwindEx (Hint: 1236)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: __C_specific_handler (Hint: 1584)
  Imported DLL: msvcrt.dll
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _fpreset (Hint: 223)
    - Function: _initterm (Hint: 283)
    - Function: _onexit (Hint: 551)
    - Function: abort (Hint: 901)
    - Function: calloc (Hint: 918)
    - Function: exit (Hint: 931)
    - Function: fprintf (Hint: 951)
    - Function: free (Hint: 958)
    - Function: fwrite (Hint: 971)
    - Function: malloc (Hint: 1018)
    - Function: memcmp (Hint: 1025)
    - Function: memcpy (Hint: 1026)
    - Function: memmove (Hint: 1027)
    - Function: memset (Hint: 1028)
    - Function: signal (Hint: 1058)
    - Function: strlen (Hint: 1081)
    - Function: strncmp (Hint: 1084)
    - Function: vfprintf (Hint: 1118)
  Imported DLL: ntdll.dll
    - Function: NtCreateNamedPipeFile (Hint: 330)
  Imported DLL: advapi32.dll
    - Function: ControlService (Hint: 0)
    - Function: OpenProcessToken (Hint: 0)
    - Function: OpenSCManagerW (Hint: 0)
    - Function: OpenServiceW (Hint: 0)
    - Function: RegCloseKey (Hint: 0)
    - Function: RegEnumKeyExW (Hint: 0)
    - Function: RegEnumValueW (Hint: 0)
    - Function: RegOpenKeyExA (Hint: 0)
    - Function: RegOpenKeyExW (Hint: 0)
    - Function: RegQueryInfoKeyW (Hint: 0)
    - Function: RegQueryValueExW (Hint: 0)
    - Function: RegSetValueExA (Hint: 0)
    - Function: SystemFunction036 (Hint: 0)
  Imported DLL: bcrypt.dll
    - Function: BCryptGenRandom (Hint: 0)
  Imported DLL: kernel32.dll
    - Function: AddVectoredExceptionHandler (Hint: 0)
    - Function: CancelIo (Hint: 0)
    - Function: CompareStringOrdinal (Hint: 0)
    - Function: CopyFileExW (Hint: 0)
    - Function: CreateDirectoryW (Hint: 0)
    - Function: CreateEventW (Hint: 0)
    - Function: CreateFileMappingA (Hint: 0)
    - Function: CreateHardLinkW (Hint: 0)
    - Function: CreatePipe (Hint: 0)
    - Function: CreateProcessW (Hint: 0)
    - Function: CreateRemoteThread (Hint: 0)
    - Function: CreateSymbolicLinkW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateToolhelp32Snapshot (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: DeleteFileW (Hint: 0)
    - Function: DeleteProcThreadAttributeList (Hint: 0)
    - Function: DeviceIoControl (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: FileTimeToSystemTime (Hint: 0)
    - Function: FindClose (Hint: 0)
    - Function: FindFirstFileExW (Hint: 0)
    - Function: FindNextFileW (Hint: 0)
    - Function: FlushFileBuffers (Hint: 0)
    - Function: FormatMessageW (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: GetCommandLineW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: GetConsoleOutputCP (Hint: 0)
    - Function: GetCurrentDirectoryW (Hint: 0)
    - Function: GetCurrentProcess (Hint: 0)
    - Function: GetCurrentProcessId (Hint: 0)
    - Function: GetCurrentThread (Hint: 0)
    - Function: GetCurrentThreadId (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetEnvironmentVariableW (Hint: 0)
    - Function: GetExitCodeProcess (Hint: 0)
    - Function: GetFileAttributesW (Hint: 0)
    - Function: GetFileInformationByHandle (Hint: 0)
    - Function: GetFileInformationByHandleEx (Hint: 0)
    - Function: GetFileSizeEx (Hint: 0)
    - Function: GetFileType (Hint: 0)
    - Function: GetFinalPathNameByHandleW (Hint: 0)
    - Function: GetFullPathNameW (Hint: 0)
    - Function: GetModuleFileNameW (Hint: 0)
    - Function: GetProcessHeap (Hint: 0)
    - Function: GetProcessId (Hint: 0)
    - Function: GetStartupInfoA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetSystemDirectoryW (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemTimePreciseAsFileTime (Hint: 0)
    - Function: GetTempPathW (Hint: 0)
    - Function: GetWindowsDirectoryW (Hint: 0)
    - Function: HeapAlloc (Hint: 0)
    - Function: HeapFree (Hint: 0)
    - Function: HeapReAlloc (Hint: 0)
    - Function: InitOnceBeginInitialize (Hint: 0)
    - Function: InitOnceComplete (Hint: 0)
    - Function: InitializeProcThreadAttributeList (Hint: 0)
    - Function: IsDebuggerPresent (Hint: 0)
    - Function: LockFileEx (Hint: 0)
    - Function: MapViewOfFile (Hint: 0)
    - Function: Module32FirstW (Hint: 0)
    - Function: Module32NextW (Hint: 0)
    - Function: MoveFileExW (Hint: 0)
    - Function: MultiByteToWideChar (Hint: 0)
    - Function: OpenProcess (Hint: 0)
    - Function: Process32First (Hint: 0)
    - Function: Process32Next (Hint: 0)
    - Function: QueryPerformanceCounter (Hint: 0)
    - Function: QueryPerformanceFrequency (Hint: 0)
    - Function: ReadConsoleW (Hint: 0)
    - Function: ReadFileEx (Hint: 0)
    - Function: RemoveDirectoryW (Hint: 0)
    - Function: RtlCaptureContext (Hint: 0)
    - Function: RtlLookupFunctionEntry (Hint: 0)
    - Function: RtlVirtualUnwind (Hint: 0)
    - Function: SetCurrentDirectoryW (Hint: 0)
    - Function: SetEnvironmentVariableW (Hint: 0)
    - Function: SetFileAttributesW (Hint: 0)
    - Function: SetFileInformationByHandle (Hint: 0)
    - Function: SetFilePointerEx (Hint: 0)
    - Function: SetFileTime (Hint: 0)
    - Function: SetLastError (Hint: 0)
    - Function: SetThreadStackGuarantee (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: Sleep (Hint: 0)
    - Function: SleepEx (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: TerminateProcess (Hint: 0)
    - Function: TlsAlloc (Hint: 0)
    - Function: TlsFree (Hint: 0)
    - Function: TlsGetValue (Hint: 0)
    - Function: TlsSetValue (Hint: 0)
    - Function: UnlockFile (Hint: 0)
    - Function: UnmapViewOfFile (Hint: 0)
    - Function: UpdateProcThreadAttribute (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: WideCharToMultiByte (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WriteFileEx (Hint: 0)
    - Function: WriteProcessMemory (Hint: 0)
  Imported DLL: ntdll.dll
    - Function: NtOpenFile (Hint: 0)
    - Function: NtReadFile (Hint: 0)
    - Function: NtWriteFile (Hint: 0)
  Imported DLL: psapi.dll
    - Function: GetProcessMemoryInfo (Hint: 0)
  Imported DLL: user32.dll
    - Function: CallNextHookEx (Hint: 0)
    - Function: GetKeyboardState (Hint: 0)
    - Function: SetWindowsHookExA (Hint: 0)
    - Function: ToUnicode (Hint: 0)
    - Function: UnhookWindowsHookEx (Hint: 0)
  Imported DLL: userenv.dll
    - Function: GetUserProfileDirectoryW (Hint: 0)
  Imported DLL: ws2_32.dll
    - Function: WSACleanup (Hint: 0)
    - Function: WSAStartup (Hint: 0)
    - Function: freeaddrinfo (Hint: 0)
    - Function: getaddrinfo (Hint: 0)
    - Function: select (Hint: 0)
  Imported DLL: api-ms-win-core-synch-l1-2-0.dll
    - Function: WaitOnAddress (Hint: 3)
    - Function: WakeByAddressAll (Hint: 1)
    - Function: WakeByAddressSingle (Hint: 2)
  Imported DLL: bcryptprimitives.dll
    - Function: ProcessPrng (Hint: 1)
[END IMPORTS ANALYSIS - 20 DLLs imported]

[INFO] Entry point RVA: 0x63860
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x252800
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/timmytv.exe':
  - Section '.text': 2435072 bytes at offset 0x600
[+] Success: Extracted 2435072 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/timmytv.exe_shellcode.bin'
[INFO] SHA256: fc9c6103b16762cb6ae7c26935a3e48f36518ac53a2060e22435ba59214b82f8
[INFO] Entropy: 6.1666 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x5F840
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x110400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/cert_scraper.exe':
  - Section '.text': 1115136 bytes at offset 0x600
[+] Success: Extracted 1115136 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/cert_scraper.exe_shellcode.bin'
[INFO] SHA256: 92e32e76f96fcc6aa063f12c3f7e1f3ba7bb868fb0820ab45a20d8078c51877b
[INFO] Entropy: 6.1907 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x4200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/installer.exe':
  - Section '.text': 16896 bytes at offset 0x600
[+] Success: Extracted 16896 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/installer.exe_shellcode.bin'
[INFO] SHA256: ff5e04ed8f48b6f99f7bf7a16c28521a57a076d0995498142f90f4593a2ae9ce
[INFO] Entropy: 5.6976 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: CryptAcquireContextA (Hint: 1194)
    - Function: CryptCreateHash (Hint: 1197)
    - Function: CryptDecrypt (Hint: 1198)
    - Function: CryptDeriveKey (Hint: 1199)
    - Function: CryptDestroyHash (Hint: 1200)
    - Function: CryptDestroyKey (Hint: 1201)
    - Function: CryptGenRandom (Hint: 1211)
    - Function: CryptHashData (Hint: 1218)
    - Function: CryptReleaseContext (Hint: 1221)
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExA (Hint: 1652)
    - Function: RegQueryValueExA (Hint: 1665)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CreateThread (Hint: 252)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: ExitProcess (Hint: 366)
    - Function: GetLastError (Hint: 630)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDebuggerPresent (Hint: 920)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualAlloc (Hint: 1486)
    - Function: VirtualFree (Hint: 1489)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForSingleObject (Hint: 1503)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: _time64 (Hint: 693)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: memmove (Hint: 1032)
    - Function: rand (Hint: 1051)
    - Function: signal (Hint: 1063)
    - Function: srand (Hint: 1072)
    - Function: strcat_s (Hint: 1077)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strstr (Hint: 1095)
    - Function: vfprintf (Hint: 1123)
  Imported DLL: WININET.dll
    - Function: InternetCloseHandle (Hint: 145)
    - Function: InternetOpenA (Hint: 194)
    - Function: InternetOpenUrlA (Hint: 195)
    - Function: InternetReadFile (Hint: 202)
  Imported DLL: libgcc_s_seh-1.dll
    - Function: _Unwind_Resume (Hint: 15)
  Imported DLL: libstdc++-6.dll
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv (Hint: 731)
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv (Hint: 743)
    - Function: _ZNSaIcEC1Ev (Hint: 1265)
    - Function: _ZNSaIcED1Ev (Hint: 1268)
    - Function: _ZNSaIcED2Ev (Hint: 1269)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv (Hint: 3670)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEy (Hint: 3673)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcRKS3_ (Hint: 3675)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv (Hint: 3685)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEy (Hint: 3686)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsEPcPKcS7_ (Hint: 3689)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendEPKc (Hint: 3711)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc (Hint: 3739)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERyy (Hint: 3769)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_ (Hint: 3775)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev (Hint: 3808)
    - Function: _ZSt17__throw_bad_allocv (Hint: 4624)
    - Function: _ZSt19__throw_logic_errorPKc (Hint: 4638)
    - Function: _ZSt20__throw_length_errorPKc (Hint: 4646)
    - Function: _ZdaPv (Hint: 5611)
    - Function: _ZdlPvy (Hint: 5621)
    - Function: _Znay (Hint: 5623)
    - Function: _Znwy (Hint: 5627)
    - Function: __cxa_begin_catch (Hint: 5637)
    - Function: __cxa_end_catch (Hint: 5642)
    - Function: __cxa_rethrow (Hint: 5653)
    - Function: __gxx_personality_seh0 (Hint: 5670)
[END IMPORTS ANALYSIS - 6 DLLs imported]

[INFO] Entry point RVA: 0x777A0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 8
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2BB400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/uhmento_O.exe':
  - Section '.text': 2864128 bytes at offset 0x600
[+] Success: Extracted 2864128 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/uhmento_O.exe_shellcode.bin'
[INFO] SHA256: 4da9e10751fa4d58f43672c786b1ceb12ea293d2744e6fe56481746f75a0d433
[INFO] Entropy: 6.2094 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WerSetFlags (Hint: 0)
    - Function: WerGetFlags (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: TlsAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: RtlVirtualUnwind (Hint: 0)
    - Function: RtlLookupFunctionEntry (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: RaiseFailFastException (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: LoadLibraryExW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetErrorMode (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetCurrentThreadId (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
    - Function: AddVectoredContinueHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0xB0A00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/IG_coiled.exe':
  - Section '.text': 723456 bytes at offset 0x600
[+] Success: Extracted 723456 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/IG_coiled.exe_shellcode.bin'
[INFO] SHA256: 13d9a8a786a87c9e1bf36dd00958aeccee1dc44826a781d6442e05f5a63d738e
[INFO] Entropy: 6.1427 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: AdjustTokenPrivileges (Hint: 1032)
    - Function: ChangeServiceConfig2W (Hint: 1092)
    - Function: CloseServiceHandle (Hint: 1102)
    - Function: LookupPrivilegeValueW (Hint: 1432)
    - Function: OpenProcessToken (Hint: 1534)
    - Function: OpenSCManagerW (Hint: 1536)
    - Function: OpenServiceW (Hint: 1538)
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExW (Hint: 1653)
    - Function: RegSetValueExW (Hint: 1682)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CreateProcessW (Hint: 239)
    - Function: CreateSemaphoreW (Hint: 246)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetCurrentProcess (Hint: 552)
    - Function: GetCurrentThreadId (Hint: 557)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleFileNameW (Hint: 650)
    - Function: GetModuleHandleW (Hint: 654)
    - Function: GetProcAddress (Hint: 710)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: GetWindowsDirectoryW (Hint: 832)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDBCSLeadByteEx (Hint: 919)
    - Function: IsDebuggerPresent (Hint: 920)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: LoadLibraryW (Hint: 991)
    - Function: MultiByteToWideChar (Hint: 1036)
    - Function: RaiseException (Hint: 1153)
    - Function: ReleaseSemaphore (Hint: 1196)
    - Function: RtlCaptureContext (Hint: 1223)
    - Function: RtlLookupFunctionEntry (Hint: 1230)
    - Function: RtlUnwindEx (Hint: 1236)
    - Function: RtlVirtualUnwind (Hint: 1237)
    - Function: SetLastError (Hint: 1334)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsAlloc (Hint: 1443)
    - Function: TlsFree (Hint: 1444)
    - Function: TlsGetValue (Hint: 1445)
    - Function: TlsSetValue (Hint: 1446)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForSingleObject (Hint: 1503)
    - Function: WideCharToMultiByte (Hint: 1547)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: ___lc_codepage_func (Hint: 64)
    - Function: ___mb_cur_max_func (Hint: 67)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _errno (Hint: 190)
    - Function: _filelengthi64 (Hint: 210)
    - Function: _fileno (Hint: 211)
    - Function: _fmode (Hint: 220)
    - Function: _fstat64 (Hint: 234)
    - Function: _initterm (Hint: 285)
    - Function: _lseeki64 (Hint: 396)
    - Function: _onexit (Hint: 553)
    - Function: _strnicmp (Hint: 658)
    - Function: _wfopen (Hint: 832)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fclose (Hint: 940)
    - Function: fflush (Hint: 943)
    - Function: fgetpos (Hint: 945)
    - Function: fopen (Hint: 953)
    - Function: fprintf (Hint: 956)
    - Function: fputc (Hint: 958)
    - Function: fputs (Hint: 959)
    - Function: fread (Hint: 962)
    - Function: free (Hint: 963)
    - Function: fsetpos (Hint: 971)
    - Function: fwrite (Hint: 976)
    - Function: getc (Hint: 980)
    - Function: getwc (Hint: 985)
    - Function: isspace (Hint: 998)
    - Function: iswctype (Hint: 1004)
    - Function: localeconv (Hint: 1017)
    - Function: malloc (Hint: 1023)
    - Function: memchr (Hint: 1029)
    - Function: memcmp (Hint: 1030)
    - Function: memcpy (Hint: 1031)
    - Function: memmove (Hint: 1032)
    - Function: memset (Hint: 1033)
    - Function: putc (Hint: 1043)
    - Function: putwc (Hint: 1046)
    - Function: realloc (Hint: 1052)
    - Function: setlocale (Hint: 1061)
    - Function: setvbuf (Hint: 1062)
    - Function: signal (Hint: 1063)
    - Function: strcmp (Hint: 1079)
    - Function: strcoll (Hint: 1080)
    - Function: strerror (Hint: 1084)
    - Function: strftime (Hint: 1085)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strxfrm (Hint: 1101)
    - Function: towlower (Hint: 1118)
    - Function: towupper (Hint: 1119)
    - Function: ungetc (Hint: 1120)
    - Function: ungetwc (Hint: 1121)
    - Function: vfprintf (Hint: 1123)
    - Function: wcscat_s (Hint: 1141)
    - Function: wcscoll (Hint: 1144)
    - Function: wcsftime (Hint: 1148)
    - Function: wcslen (Hint: 1149)
    - Function: wcsxfrm (Hint: 1168)
    - Function: _write (Hint: 1212)
    - Function: _read (Hint: 1254)
    - Function: _fileno (Hint: 1281)
    - Function: _fdopen (Hint: 1285)
    - Function: _close (Hint: 1301)
  Imported DLL: ole32.dll
    - Function: CoTaskMemFree (Hint: 129)
  Imported DLL: SHELL32.dll
    - Function: SHGetKnownFolderPath (Hint: 232)
    - Function: ShellExecuteW (Hint: 340)
  Imported DLL: SHLWAPI.dll
    - Function: PathFileExistsW (Hint: 74)
  Imported DLL: USER32.dll
    - Function: FindWindowW (Hint: 273)
[END IMPORTS ANALYSIS - 7 DLLs imported]

[INFO] Entry point RVA: 0x5D660
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x8AA00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/unitarian.exe':
  - Section '.text': 567808 bytes at offset 0x600
[+] Success: Extracted 567808 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/unitarian.exe_shellcode.bin'
[INFO] SHA256: 466d864f18da283abb8560f9aabcc967f63df6929ae4750a4fb3563eb8addd10
[INFO] Entropy: 6.1678 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x1350
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 11
[INFO] Input file is a DLL.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0xAE800
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/keylogger.dll':
  - Section '.text': 714752 bytes at offset 0x400
[+] Success: Extracted 714752 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/keylogger.dll_shellcode.bin'
[INFO] SHA256: 52ae2d57c6b0b6d4fa43499a5d1b5c8be6e94335d665264a0846ff391aafabd4
[INFO] Entropy: 6.3907 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: SystemFunction036 (Hint: 757)
  Imported DLL: KERNEL32.dll
    - Function: AddVectoredExceptionHandler (Hint: 17)
    - Function: CancelIo (Hint: 52)
    - Function: CloseHandle (Hint: 69)
    - Function: CompareStringOrdinal (Hint: 85)
    - Function: CopyFileExW (Hint: 97)
    - Function: CreateDirectoryW (Hint: 111)
    - Function: CreateEventW (Hint: 116)
    - Function: CreateFileMappingA (Hint: 121)
    - Function: CreateFileW (Hint: 128)
    - Function: CreateHardLinkW (Hint: 132)
    - Function: CreatePipe (Hint: 146)
    - Function: CreateProcessW (Hint: 150)
    - Function: CreateSymbolicLinkW (Hint: 160)
    - Function: CreateThread (Hint: 162)
    - Function: CreateToolhelp32Snapshot (Hint: 171)
    - Function: CreateWaitableTimerExW (Hint: 176)
    - Function: DeleteFileW (Hint: 197)
    - Function: DeleteProcThreadAttributeList (Hint: 198)
    - Function: DeviceIoControl (Hint: 208)
    - Function: DuplicateHandle (Hint: 219)
    - Function: ExitProcess (Hint: 272)
    - Function: FindClose (Hint: 290)
    - Function: FindFirstFileExW (Hint: 296)
    - Function: FindNextFileW (Hint: 313)
    - Function: FlushFileBuffers (Hint: 332)
    - Function: FormatMessageW (Hint: 340)
    - Function: FreeEnvironmentStringsW (Hint: 343)
    - Function: GetCommandLineW (Hint: 378)
    - Function: GetConsoleMode (Hint: 402)
    - Function: GetConsoleOutputCP (Hint: 405)
    - Function: GetCurrentDirectoryW (Hint: 421)
    - Function: GetCurrentProcess (Hint: 427)
    - Function: GetCurrentProcessId (Hint: 428)
    - Function: GetCurrentThread (Hint: 431)
    - Function: GetCurrentThreadId (Hint: 432)
    - Function: GetEnvironmentStringsW (Hint: 455)
    - Function: GetEnvironmentVariableW (Hint: 457)
    - Function: GetExitCodeProcess (Hint: 460)
    - Function: GetFileAttributesW (Hint: 467)
    - Function: GetFileInformationByHandle (Hint: 469)
    - Function: GetFileInformationByHandleEx (Hint: 470)
    - Function: GetFileSizeEx (Hint: 474)
    - Function: GetFileType (Hint: 476)
    - Function: GetFinalPathNameByHandleW (Hint: 478)
    - Function: GetFullPathNameW (Hint: 487)
    - Function: GetLastError (Hint: 494)
    - Function: GetModuleFileNameW (Hint: 513)
    - Function: GetModuleHandleA (Hint: 514)
    - Function: GetModuleHandleW (Hint: 517)
    - Function: GetOverlappedResult (Hint: 548)
    - Function: GetProcAddress (Hint: 570)
    - Function: GetProcessHeap (Hint: 576)
    - Function: GetProcessId (Hint: 578)
    - Function: GetStdHandle (Hint: 606)
    - Function: GetSystemDirectoryW (Hint: 620)
    - Function: GetSystemInfo (Hint: 623)
    - Function: GetSystemTimePreciseAsFileTime (Hint: 630)
    - Function: GetTempPathW (Hint: 642)
    - Function: GetWindowsDirectoryW (Hint: 689)
    - Function: HeapAlloc (Hint: 720)
    - Function: HeapFree (Hint: 724)
    - Function: HeapReAlloc (Hint: 727)
    - Function: InitOnceBeginInitialize (Hint: 735)
    - Function: InitOnceComplete (Hint: 736)
    - Function: InitializeProcThreadAttributeList (Hint: 745)
    - Function: LockFileEx (Hint: 841)
    - Function: MapViewOfFile (Hint: 845)
    - Function: Module32FirstW (Hint: 850)
    - Function: Module32NextW (Hint: 852)
    - Function: MoveFileExW (Hint: 855)
    - Function: MultiByteToWideChar (Hint: 862)
    - Function: QueryPerformanceCounter (Hint: 940)
    - Function: QueryPerformanceFrequency (Hint: 941)
    - Function: ReadConsoleW (Hint: 963)
    - Function: ReadFile (Hint: 966)
    - Function: ReadFileEx (Hint: 967)
    - Function: RemoveDirectoryW (Hint: 989)
    - Function: RtlCaptureContext (Hint: 1010)
    - Function: RtlLookupFunctionEntry (Hint: 1017)
    - Function: RtlVirtualUnwind (Hint: 1024)
    - Function: SetCurrentDirectoryW (Hint: 1062)
    - Function: SetEnvironmentVariableW (Hint: 1073)
    - Function: SetFileAttributesW (Hint: 1082)
    - Function: SetFileInformationByHandle (Hint: 1085)
    - Function: SetFilePointerEx (Hint: 1088)
    - Function: SetFileTime (Hint: 1091)
    - Function: SetHandleInformation (Hint: 1098)
    - Function: SetLastError (Hint: 1101)
    - Function: SetThreadStackGuarantee (Hint: 1147)
    - Function: SetWaitableTimer (Hint: 1166)
    - Function: Sleep (Hint: 1172)
    - Function: SleepEx (Hint: 1175)
    - Function: SwitchToThread (Hint: 1180)
    - Function: TerminateProcess (Hint: 1185)
    - Function: TlsAlloc (Hint: 1189)
    - Function: TlsFree (Hint: 1190)
    - Function: TlsGetValue (Hint: 1191)
    - Function: TlsSetValue (Hint: 1192)
    - Function: UnlockFile (Hint: 1204)
    - Function: UnmapViewOfFile (Hint: 1206)
    - Function: UpdateProcThreadAttribute (Hint: 1214)
    - Function: WaitForMultipleObjects (Hint: 1238)
    - Function: WaitForSingleObject (Hint: 1240)
    - Function: WideCharToMultiByte (Hint: 1267)
    - Function: WriteConsoleW (Hint: 1284)
    - Function: WriteFileEx (Hint: 1286)
  Imported DLL: USER32.dll
    - Function: CallNextHookEx (Hint: 26)
    - Function: GetAsyncKeyState (Hint: 239)
    - Function: GetForegroundWindow (Hint: 287)
    - Function: GetKeyState (Hint: 302)
    - Function: GetKeyboardState (Hint: 307)
    - Function: GetWindowTextW (Hint: 419)
    - Function: SetWindowsHookExW (Hint: 692)
    - Function: ToUnicode (Hint: 719)
  Imported DLL: api-ms-win-core-synch-l1-2-0.dll
    - Function: WaitOnAddress (Hint: 3)
    - Function: WakeByAddressAll (Hint: 1)
    - Function: WakeByAddressSingle (Hint: 2)
  Imported DLL: bcryptprimitives.dll
    - Function: ProcessPrng (Hint: 1)
  Imported DLL: bcrypt.dll
    - Function: BCryptGenRandom (Hint: 30)
  Imported DLL: KERNEL32.dll
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: RaiseException (Hint: 1153)
    - Function: RtlUnwindEx (Hint: 1236)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
  Imported DLL: msvcrt.dll
    - Function: __iob_func (Hint: 84)
    - Function: _amsg_exit (Hint: 121)
    - Function: _initterm (Hint: 285)
    - Function: _lock (Hint: 387)
    - Function: _unlock (Hint: 714)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: memcmp (Hint: 1030)
    - Function: memcpy (Hint: 1031)
    - Function: memmove (Hint: 1032)
    - Function: memset (Hint: 1033)
    - Function: realloc (Hint: 1052)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: vfprintf (Hint: 1123)
  Imported DLL: ntdll.dll
    - Function: NtCreateNamedPipeFile (Hint: 324)
    - Function: NtOpenFile (Hint: 450)
    - Function: NtReadFile (Hint: 553)
    - Function: NtWriteFile (Hint: 693)
    - Function: RtlNtStatusToDosError (Hint: 1317)
  Imported DLL: USERENV.dll
    - Function: GetUserProfileDirectoryW (Hint: 36)
  Imported DLL: WS2_32.dll
    - Function: WSACleanup (Hint: 31)
    - Function: WSADuplicateSocketW (Hint: 39)
    - Function: WSAGetLastError (Hint: 48)
    - Function: WSARecv (Hint: 73)
    - Function: WSASend (Hint: 78)
    - Function: WSASocketW (Hint: 88)
    - Function: WSAStartup (Hint: 89)
    - Function: accept (Hint: 162)
    - Function: bind (Hint: 163)
    - Function: closesocket (Hint: 164)
    - Function: connect (Hint: 165)
    - Function: freeaddrinfo (Hint: 166)
    - Function: getaddrinfo (Hint: 167)
    - Function: getpeername (Hint: 172)
    - Function: getsockname (Hint: 177)
    - Function: getsockopt (Hint: 178)
    - Function: ioctlsocket (Hint: 185)
    - Function: listen (Hint: 186)
    - Function: recv (Hint: 189)
    - Function: recvfrom (Hint: 190)
    - Function: select (Hint: 191)
    - Function: send (Hint: 192)
    - Function: sendto (Hint: 193)
    - Function: setsockopt (Hint: 194)
    - Function: shutdown (Hint: 195)
[END IMPORTS ANALYSIS - 11 DLLs imported]
[EXPORTS ANALYSIS - keylogger.dll]
  Base Ordinal: 1
  Number of Functions: 1
  Number of Names: 1
    - Function: run_keylogger
[END EXPORTS ANALYSIS]
[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 4
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/skeeterspit.exe':
  - Section '.text': 1024 bytes at offset 0x400
[+] Success: Extracted 1024 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/skeeterspit.exe_shellcode.bin'
[INFO] SHA256: fe6c8151c51d80dc504442e24940f17b1455b91c4d9ba966298c8aea1b4a1bde
[INFO] Entropy: 3.1065 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: CloseServiceHandle (Hint: 1102)
    - Function: ControlService (Hint: 1107)
    - Function: OpenSCManagerW (Hint: 1536)
    - Function: OpenServiceW (Hint: 1538)
    - Function: QueryServiceStatus (Hint: 1593)
  Imported DLL: KERNEL32.dll
    - Function: ExitProcess (Hint: 366)
    - Function: GetCurrentProcessId (Hint: 553)
    - Function: GetProcessHeap (Hint: 716)
    - Function: GetTickCount64 (Hint: 800)
    - Function: QueryPerformanceCounter (Hint: 1131)
  Imported DLL: ntdll.dll
    - Function: RtlGetVersion (Hint: 1145)
[END IMPORTS ANALYSIS - 3 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2A00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/persistence.exe':
  - Section '.text': 10752 bytes at offset 0x600
[+] Success: Extracted 10752 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/persistence.exe_shellcode.bin'
[INFO] SHA256: d30aa2ced0139ea84c37b6ffdf91365da1d117b3ece3e9353baf8bfbf658b1c0
[INFO] Entropy: 5.8643 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: libgcc_s_seh-1.dll
    - Function: _Unwind_Resume (Hint: 15)
  Imported DLL: libstdc++-6.dll
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv (Hint: 731)
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv (Hint: 743)
    - Function: _ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13get_allocatorEv (Hint: 768)
    - Function: _ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE4sizeEv (Hint: 790)
    - Function: _ZNKSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE7_M_dataEv (Hint: 804)
    - Function: _ZNKSt7__cxx1118basic_stringstreamIwSt11char_traitsIwESaIwEE3strEv (Hint: 822)
    - Function: _ZNSaIcEC1Ev (Hint: 1265)
    - Function: _ZNSaIcED1Ev (Hint: 1268)
    - Function: _ZNSaIcED2Ev (Hint: 1269)
    - Function: _ZNSaIwEC1ERKS_ (Hint: 1270)
    - Function: _ZNSaIwEC1Ev (Hint: 1271)
    - Function: _ZNSaIwED1Ev (Hint: 1274)
    - Function: _ZNSaIwED2Ev (Hint: 1275)
    - Function: _ZNSolsEPFRSoS_E (Hint: 1521)
    - Function: _ZNSt13basic_ostreamIwSt11char_traitsIwEElsEPFRS2_S3_E (Hint: 2385)
    - Function: _ZNSt13basic_ostreamIwSt11char_traitsIwEElsEi (Hint: 2394)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv (Hint: 3670)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEy (Hint: 3673)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcRKS3_ (Hint: 3675)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv (Hint: 3685)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEy (Hint: 3686)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc (Hint: 3739)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERyy (Hint: 3769)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev (Hint: 3808)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE10_M_disposeEv (Hint: 3821)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE11_M_capacityEy (Hint: 3824)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE12_Alloc_hiderC1EPwRKS3_ (Hint: 3826)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_M_local_dataEv (Hint: 3836)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_M_set_lengthEy (Hint: 3837)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE13_S_copy_charsEPwPKwS7_ (Hint: 3840)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE3endEv (Hint: 3848)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE5beginEv (Hint: 3854)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE6appendEPKw (Hint: 3862)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE6appendEPKwy (Hint: 3863)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE6appendERKS4_ (Hint: 3864)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE7_M_dataEPw (Hint: 3890)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE7reserveEy (Hint: 3915)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEE9_M_createERyy (Hint: 3920)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1EOS4_ (Hint: 3926)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEEC1ERKS3_ (Hint: 3930)
    - Function: _ZNSt7__cxx1112basic_stringIwSt11char_traitsIwESaIwEED1Ev (Hint: 3959)
    - Function: _ZNSt7__cxx1118basic_stringstreamIwSt11char_traitsIwESaIwEEC1Ev (Hint: 4138)
    - Function: _ZNSt7__cxx1118basic_stringstreamIwSt11char_traitsIwESaIwEED1Ev (Hint: 4144)
    - Function: _ZNSt8ios_base4InitC1Ev (Hint: 4392)
    - Function: _ZNSt8ios_base4InitD1Ev (Hint: 4394)
    - Function: _ZSt19__throw_logic_errorPKc (Hint: 4638)
    - Function: _ZSt4cout (Hint: 4666)
    - Function: _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_ (Hint: 4667)
    - Function: _ZSt4endlIwSt11char_traitsIwEERSt13basic_ostreamIT_T0_ES6_ (Hint: 4668)
    - Function: _ZSt5wcerr (Hint: 4674)
    - Function: _ZSt5wcout (Hint: 4676)
    - Function: _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc (Hint: 4772)
    - Function: _ZStlsIwSt11char_traitsIwEERSt13basic_ostreamIT_T0_ES6_PKS3_ (Hint: 4791)
    - Function: _ZStlsIwSt11char_traitsIwESaIwEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE (Hint: 4801)
    - Function: __cxa_begin_catch (Hint: 5637)
    - Function: __cxa_end_catch (Hint: 5642)
    - Function: __cxa_rethrow (Hint: 5653)
    - Function: __gxx_personality_seh0 (Hint: 5670)
  Imported DLL: KERNEL32.dll
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleFileNameW (Hint: 650)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: signal (Hint: 1063)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: system (Hint: 1108)
    - Function: vfprintf (Hint: 1123)
    - Function: wcslen (Hint: 1149)
[END IMPORTS ANALYSIS - 4 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x86 (32-bit)
[INFO] Number of sections: 4
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/windefend_killer.exe':
  - Section '.text': 512 bytes at offset 0x400
[+] Success: Extracted 512 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/windefend_killer.exe_shellcode.bin'
[INFO] SHA256: b9434abf0961eb228381f4257296710356df474fb787e4479b0c84558b176bc4
[INFO] Entropy: 2.6678 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: CloseHandle (Hint: 1)
    - Function: GetProcAddress (Hint: 2)
    - Function: LoadLibraryA (Hint: 3)
    - Function: LocalAlloc (Hint: 4)
    - Function: LocalFree (Hint: 5)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 4
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/imon.exe':
  - Section '.text': 1024 bytes at offset 0x400
[+] Success: Extracted 1024 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/imon.exe_shellcode.bin'
[INFO] SHA256: c90de22cd5f83c2528984372d98a7f5efc10b1ae603b2e5b488543852a65bc9a
[INFO] Entropy: 4.7161 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegCreateKeyExA (Hint: 1612)
    - Function: RegSetValueExA (Hint: 1681)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CreateFileA (Hint: 204)
    - Function: ExitProcess (Hint: 366)
    - Function: GetModuleHandleA (Hint: 651)
    - Function: GetProcAddress (Hint: 710)
    - Function: LoadLibraryA (Hint: 988)
    - Function: WriteFile (Hint: 1567)
  Imported DLL: USER32.dll
    - Function: CallNextHookEx (Hint: 31)
    - Function: DispatchMessageA (Hint: 185)
    - Function: GetMessageA (Hint: 380)
    - Function: SetWindowsHookExA (Hint: 856)
    - Function: TranslateMessage (Hint: 897)
    - Function: UnhookWindowsHookEx (Hint: 901)
[END IMPORTS ANALYSIS - 3 DLLs imported]

[INFO] Entry point RVA: 0x288E
[INFO] Machine type: x86 (32-bit)
[INFO] Number of sections: 3
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x2000, Raw=0x200, Size=0xA00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/module_5.exe':
  - Section '.text': 2560 bytes at offset 0x200
[+] Success: Extracted 2560 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/module_5.exe_shellcode.bin'
[INFO] SHA256: b6c015aebf25009c7c741a4d0b78f82a2fd3488b5de6921732ecaba2d00c60a3
[INFO] Entropy: 4.4311 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: mscoree.dll
    - Function: _CorExeMain (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x4200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/installer_1.exe':
  - Section '.text': 16896 bytes at offset 0x600
[+] Success: Extracted 16896 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/installer_1.exe_shellcode.bin'
[INFO] SHA256: ff5e04ed8f48b6f99f7bf7a16c28521a57a076d0995498142f90f4593a2ae9ce
[INFO] Entropy: 5.6976 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: CryptAcquireContextA (Hint: 1194)
    - Function: CryptCreateHash (Hint: 1197)
    - Function: CryptDecrypt (Hint: 1198)
    - Function: CryptDeriveKey (Hint: 1199)
    - Function: CryptDestroyHash (Hint: 1200)
    - Function: CryptDestroyKey (Hint: 1201)
    - Function: CryptGenRandom (Hint: 1211)
    - Function: CryptHashData (Hint: 1218)
    - Function: CryptReleaseContext (Hint: 1221)
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExA (Hint: 1652)
    - Function: RegQueryValueExA (Hint: 1665)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CreateThread (Hint: 252)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: ExitProcess (Hint: 366)
    - Function: GetLastError (Hint: 630)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDebuggerPresent (Hint: 920)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualAlloc (Hint: 1486)
    - Function: VirtualFree (Hint: 1489)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForSingleObject (Hint: 1503)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: _time64 (Hint: 693)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: memmove (Hint: 1032)
    - Function: rand (Hint: 1051)
    - Function: signal (Hint: 1063)
    - Function: srand (Hint: 1072)
    - Function: strcat_s (Hint: 1077)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strstr (Hint: 1095)
    - Function: vfprintf (Hint: 1123)
  Imported DLL: WININET.dll
    - Function: InternetCloseHandle (Hint: 145)
    - Function: InternetOpenA (Hint: 194)
    - Function: InternetOpenUrlA (Hint: 195)
    - Function: InternetReadFile (Hint: 202)
  Imported DLL: libgcc_s_seh-1.dll
    - Function: _Unwind_Resume (Hint: 15)
  Imported DLL: libstdc++-6.dll
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv (Hint: 731)
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv (Hint: 743)
    - Function: _ZNSaIcEC1Ev (Hint: 1265)
    - Function: _ZNSaIcED1Ev (Hint: 1268)
    - Function: _ZNSaIcED2Ev (Hint: 1269)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv (Hint: 3670)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEy (Hint: 3673)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcRKS3_ (Hint: 3675)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv (Hint: 3685)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEy (Hint: 3686)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsEPcPKcS7_ (Hint: 3689)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendEPKc (Hint: 3711)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc (Hint: 3739)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERyy (Hint: 3769)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_ (Hint: 3775)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev (Hint: 3808)
    - Function: _ZSt17__throw_bad_allocv (Hint: 4624)
    - Function: _ZSt19__throw_logic_errorPKc (Hint: 4638)
    - Function: _ZSt20__throw_length_errorPKc (Hint: 4646)
    - Function: _ZdaPv (Hint: 5611)
    - Function: _ZdlPvy (Hint: 5621)
    - Function: _Znay (Hint: 5623)
    - Function: _Znwy (Hint: 5627)
    - Function: __cxa_begin_catch (Hint: 5637)
    - Function: __cxa_end_catch (Hint: 5642)
    - Function: __cxa_rethrow (Hint: 5653)
    - Function: __gxx_personality_seh0 (Hint: 5670)
[END IMPORTS ANALYSIS - 6 DLLs imported]

[INFO] Entry point RVA: 0x319E
[INFO] Machine type: x86 (32-bit)
[INFO] Number of sections: 4
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x2000, Raw=0x400, Size=0x1200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/module_2.exe':
  - Section '.text': 4608 bytes at offset 0x400
[+] Success: Extracted 4608 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/module_2.exe_shellcode.bin'
[INFO] SHA256: 2c3f35160ee77100fc3d9ee59729529e5583f66bed92f459cbbcb636e3ebe3a4
[INFO] Entropy: 5.2359 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: mscoree.dll
    - Function: _CorExeMain (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0xAF600
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/IG_nvenom.exe':
  - Section '.text': 718336 bytes at offset 0x600
[+] Success: Extracted 718336 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/IG_nvenom.exe_shellcode.bin'
[INFO] SHA256: c26a7820d3a0138d4888596a75efb0486db4efcdeeef226306a8f76251732e8a
[INFO] Entropy: 6.1431 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CreateSemaphoreW (Hint: 246)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetCurrentThreadId (Hint: 557)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleHandleW (Hint: 654)
    - Function: GetProcAddress (Hint: 710)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDBCSLeadByteEx (Hint: 919)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: LoadLibraryW (Hint: 991)
    - Function: MultiByteToWideChar (Hint: 1036)
    - Function: RaiseException (Hint: 1153)
    - Function: ReleaseSemaphore (Hint: 1196)
    - Function: RtlCaptureContext (Hint: 1223)
    - Function: RtlLookupFunctionEntry (Hint: 1230)
    - Function: RtlUnwindEx (Hint: 1236)
    - Function: RtlVirtualUnwind (Hint: 1237)
    - Function: SetLastError (Hint: 1334)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsAlloc (Hint: 1443)
    - Function: TlsFree (Hint: 1444)
    - Function: TlsGetValue (Hint: 1445)
    - Function: TlsSetValue (Hint: 1446)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForSingleObject (Hint: 1503)
    - Function: WideCharToMultiByte (Hint: 1547)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: ___lc_codepage_func (Hint: 64)
    - Function: ___mb_cur_max_func (Hint: 67)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _errno (Hint: 190)
    - Function: _filelengthi64 (Hint: 210)
    - Function: _fileno (Hint: 211)
    - Function: _fmode (Hint: 220)
    - Function: _fstat64 (Hint: 234)
    - Function: _initterm (Hint: 285)
    - Function: _lseeki64 (Hint: 396)
    - Function: _onexit (Hint: 553)
    - Function: _strnicmp (Hint: 658)
    - Function: _vscprintf (Hint: 738)
    - Function: _vsnprintf (Hint: 744)
    - Function: _wfopen (Hint: 832)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fclose (Hint: 940)
    - Function: fflush (Hint: 943)
    - Function: fgetpos (Hint: 945)
    - Function: fopen (Hint: 953)
    - Function: fprintf (Hint: 956)
    - Function: fputc (Hint: 958)
    - Function: fputs (Hint: 959)
    - Function: fread (Hint: 962)
    - Function: free (Hint: 963)
    - Function: fsetpos (Hint: 971)
    - Function: fwrite (Hint: 976)
    - Function: getc (Hint: 980)
    - Function: getwc (Hint: 985)
    - Function: isspace (Hint: 998)
    - Function: iswctype (Hint: 1004)
    - Function: localeconv (Hint: 1017)
    - Function: malloc (Hint: 1023)
    - Function: memchr (Hint: 1029)
    - Function: memcmp (Hint: 1030)
    - Function: memcpy (Hint: 1031)
    - Function: memmove (Hint: 1032)
    - Function: memset (Hint: 1033)
    - Function: putc (Hint: 1043)
    - Function: putwc (Hint: 1046)
    - Function: realloc (Hint: 1052)
    - Function: setlocale (Hint: 1061)
    - Function: setvbuf (Hint: 1062)
    - Function: signal (Hint: 1063)
    - Function: strcmp (Hint: 1079)
    - Function: strcoll (Hint: 1080)
    - Function: strcpy_s (Hint: 1082)
    - Function: strerror (Hint: 1084)
    - Function: strftime (Hint: 1085)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strxfrm (Hint: 1101)
    - Function: towlower (Hint: 1118)
    - Function: towupper (Hint: 1119)
    - Function: ungetc (Hint: 1120)
    - Function: ungetwc (Hint: 1121)
    - Function: vfprintf (Hint: 1123)
    - Function: wcscoll (Hint: 1144)
    - Function: wcsftime (Hint: 1148)
    - Function: wcslen (Hint: 1149)
    - Function: wcsxfrm (Hint: 1168)
    - Function: _write (Hint: 1212)
    - Function: _read (Hint: 1254)
    - Function: _fileno (Hint: 1281)
    - Function: _fdopen (Hint: 1285)
    - Function: _close (Hint: 1301)
  Imported DLL: USER32.dll
    - Function: CallNextHookEx (Hint: 31)
    - Function: DispatchMessageA (Hint: 185)
    - Function: GetMessageA (Hint: 380)
    - Function: SetWindowsHookExA (Hint: 856)
    - Function: TranslateMessage (Hint: 897)
    - Function: UnhookWindowsHookEx (Hint: 901)
  Imported DLL: WINHTTP.dll
    - Function: WinHttpCloseHandle (Hint: 9)
    - Function: WinHttpConnect (Hint: 10)
    - Function: WinHttpCrackUrl (Hint: 22)
    - Function: WinHttpOpen (Hint: 39)
    - Function: WinHttpOpenRequest (Hint: 40)
    - Function: WinHttpReceiveResponse (Hint: 63)
    - Function: WinHttpSendRequest (Hint: 66)
[END IMPORTS ANALYSIS - 4 DLLs imported]

[INFO] Entry point RVA: 0x1530
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 9
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0xA00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/SSIW.exe':
  - Section '.text': 2560 bytes at offset 0x400
[+] Success: Extracted 2560 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/SSIW.exe_shellcode.bin'
[INFO] SHA256: 6af2e3e988c33f81b26a43fe47da8cf4931ee8f417c61c869b8b1fd913d136ec
[INFO] Entropy: 4.7763 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: KERNEL32.dll
    - Function: GetStdHandle (Hint: 746)
  Imported DLL: msvcrt.dll
    - Function: memset (Hint: 1033)
    - Function: strcmp (Hint: 1079)
[END IMPORTS ANALYSIS - 2 DLLs imported]
[EXPORTS ANALYSIS - SSIW.exe]
  Base Ordinal: 1
  Number of Functions: 1
  Number of Names: 1
    - Function: ssiw_main
[END EXPORTS ANALYSIS]
[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 19
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x4AC00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/asspiss.exe':
  - Section '.text': 306176 bytes at offset 0x600
[+] Success: Extracted 306176 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/asspiss.exe_shellcode.bin'
[INFO] SHA256: b6d64aaf4e41aa27d51a4be7aeafcff0cc8dbbea76d6cdc625386eeef1f6eefa
[INFO] Entropy: 6.4851 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: KERNEL32.dll
    - Function: CreateSemaphoreW (Hint: 246)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetLastError (Hint: 630)
    - Function: GetProcAddress (Hint: 710)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDBCSLeadByteEx (Hint: 919)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: LoadLibraryA (Hint: 988)
    - Function: MultiByteToWideChar (Hint: 1036)
    - Function: ReleaseSemaphore (Hint: 1196)
    - Function: SetLastError (Hint: 1334)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsAlloc (Hint: 1443)
    - Function: TlsGetValue (Hint: 1445)
    - Function: TlsSetValue (Hint: 1446)
    - Function: VirtualAlloc (Hint: 1486)
    - Function: VirtualFree (Hint: 1489)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForSingleObject (Hint: 1503)
    - Function: WideCharToMultiByte (Hint: 1547)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: ___lc_codepage_func (Hint: 64)
    - Function: ___mb_cur_max_func (Hint: 67)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _errno (Hint: 190)
    - Function: _filelengthi64 (Hint: 210)
    - Function: _fileno (Hint: 211)
    - Function: _fmode (Hint: 220)
    - Function: _get_osfhandle (Hint: 253)
    - Function: _initterm (Hint: 285)
    - Function: _isatty (Hint: 289)
    - Function: _lock (Hint: 387)
    - Function: _onexit (Hint: 553)
    - Function: _setmode (Hint: 602)
    - Function: _unlock (Hint: 714)
    - Function: _wfopen (Hint: 832)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: clearerr (Hint: 926)
    - Function: exit (Hint: 936)
    - Function: fclose (Hint: 940)
    - Function: ferror (Hint: 942)
    - Function: fflush (Hint: 943)
    - Function: fgetc (Hint: 944)
    - Function: fgetpos (Hint: 945)
    - Function: fgets (Hint: 946)
    - Function: fprintf (Hint: 956)
    - Function: fputc (Hint: 958)
    - Function: fread (Hint: 962)
    - Function: free (Hint: 963)
    - Function: fsetpos (Hint: 971)
    - Function: fwrite (Hint: 976)
    - Function: localeconv (Hint: 1017)
    - Function: malloc (Hint: 1023)
    - Function: memchr (Hint: 1029)
    - Function: memcmp (Hint: 1030)
    - Function: memcpy (Hint: 1031)
    - Function: memset (Hint: 1033)
    - Function: realloc (Hint: 1052)
    - Function: setvbuf (Hint: 1062)
    - Function: signal (Hint: 1063)
    - Function: strerror (Hint: 1084)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: ungetc (Hint: 1120)
    - Function: vfprintf (Hint: 1123)
    - Function: wcslen (Hint: 1149)
[END IMPORTS ANALYSIS - 2 DLLs imported]

[INFO] Entry point RVA: 0x5DC80
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x8F200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/loader_1.exe':
  - Section '.text': 586240 bytes at offset 0x600
[+] Success: Extracted 586240 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/loader_1.exe_shellcode.bin'
[INFO] SHA256: 16b6a5774bd2bd5b334233cd044b24f7057709787134d1ea4bde413ce2aff6d2
[INFO] Entropy: 6.1748 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x61300
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0xB4200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/stayawhile.exe':
  - Section '.text': 737792 bytes at offset 0x600
[+] Success: Extracted 737792 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/stayawhile.exe_shellcode.bin'
[INFO] SHA256: 9e6ff8ba910eecbc80a3ee036087a0cc34a3970fd297ddd1d011c64967c53a2b
[INFO] Entropy: 6.1675 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x86 (32-bit)
[INFO] Number of sections: 4
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/cb_wh.exe':
  - Section '.text': 1024 bytes at offset 0x400
[+] Success: Extracted 1024 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/cb_wh.exe_shellcode.bin'
[INFO] SHA256: 31bcc1967becb5076868484a1836339ca14db4f8c7c1be4b23417dab36b12262
[INFO] Entropy: 3.6898 bits/byte

[IMPORTS ANALYSIS]
[END IMPORTS ANALYSIS - 0 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x1A00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/ouroboros_core.exe':
  - Section '.text': 6656 bytes at offset 0x600
[+] Success: Extracted 6656 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/ouroboros_core.exe_shellcode.bin'
[INFO] SHA256: f2c3c2abbf1251dbceb6eb55ab00cd4c38a10596f29d34cc196a316606186df8
[INFO] Entropy: 5.7697 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: KERNEL32.dll
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: ExitProcess (Hint: 366)
    - Function: GetLastError (Hint: 630)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: __C_specific_handler (Hint: 1584)
  Imported DLL: msvcrt.dll
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: signal (Hint: 1063)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: vfprintf (Hint: 1123)
[END IMPORTS ANALYSIS - 2 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 19
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x7200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/realtekaudio2025_x64_install.exe':
  - Section '.text': 29184 bytes at offset 0x600
[+] Success: Extracted 29184 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/realtekaudio2025_x64_install.exe_shellcode.bin'
[INFO] SHA256: 5b89f9edf993a8f72f7bdb773ca1400712cf9d4b9da124fcd7d76c29c3ee30f7
[INFO] Entropy: 6.2233 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExA (Hint: 1652)
    - Function: RegSetValueExA (Hint: 1681)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CopyFileA (Hint: 177)
    - Function: CreateDirectoryA (Hint: 190)
    - Function: CreateRemoteThread (Hint: 241)
    - Function: CreateToolhelp32Snapshot (Hint: 261)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: ExpandEnvironmentStringsA (Hint: 369)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleHandleA (Hint: 651)
    - Function: GetProcAddress (Hint: 710)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDBCSLeadByteEx (Hint: 919)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: MultiByteToWideChar (Hint: 1036)
    - Function: OpenProcess (Hint: 1069)
    - Function: Process32First (Hint: 1097)
    - Function: Process32Next (Hint: 1099)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualAllocEx (Hint: 1487)
    - Function: VirtualFreeEx (Hint: 1490)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForSingleObject (Hint: 1503)
    - Function: WideCharToMultiByte (Hint: 1547)
    - Function: WriteProcessMemory (Hint: 1576)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: ___lc_codepage_func (Hint: 64)
    - Function: ___mb_cur_max_func (Hint: 67)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _errno (Hint: 190)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _lock (Hint: 387)
    - Function: _onexit (Hint: 553)
    - Function: _unlock (Hint: 714)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: fputc (Hint: 958)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: localeconv (Hint: 1017)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: signal (Hint: 1063)
    - Function: strcmp (Hint: 1079)
    - Function: strerror (Hint: 1084)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: vfprintf (Hint: 1123)
    - Function: wcslen (Hint: 1149)
[END IMPORTS ANALYSIS - 3 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x4800
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/logger_1.exe':
  - Section '.text': 18432 bytes at offset 0x600
[+] Success: Extracted 18432 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/logger_1.exe_shellcode.bin'
[INFO] SHA256: baa60309f0d521ea163d8718385dad36db8a9d0ff1eebbfee436932a6eae6239
[INFO] Entropy: 5.7424 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: GDI32.dll
    - Function: BitBlt (Hint: 20)
    - Function: CreateCompatibleBitmap (Hint: 49)
    - Function: CreateCompatibleDC (Hint: 50)
    - Function: DeleteDC (Hint: 385)
    - Function: SelectObject (Hint: 870)
  Imported DLL: gdiplus.dll
    - Function: GdipAlloc (Hint: 34)
    - Function: GdipCloneImage (Hint: 55)
    - Function: GdipCreateBitmapFromHBITMAP (Hint: 78)
    - Function: GdipDisposeImage (Hint: 153)
    - Function: GdipFree (Hint: 238)
    - Function: GdipGetImageEncoders (Hint: 287)
    - Function: GdipGetImageEncodersSize (Hint: 288)
    - Function: GdipSaveImageToStream (Hint: 498)
    - Function: GdiplusShutdown (Hint: 629)
    - Function: GdiplusStartup (Hint: 630)
  Imported DLL: KERNEL32.dll
    - Function: CreateThread (Hint: 252)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleHandleA (Hint: 651)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: GlobalLock (Hint: 850)
    - Function: GlobalSize (Hint: 854)
    - Function: GlobalUnlock (Hint: 857)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: memmove (Hint: 1032)
    - Function: signal (Hint: 1063)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: vfprintf (Hint: 1123)
    - Function: wcscmp (Hint: 1143)
  Imported DLL: ole32.dll
    - Function: CreateStreamOnHGlobal (Hint: 160)
    - Function: GetHGlobalFromStream (Hint: 179)
  Imported DLL: USER32.dll
    - Function: AddClipboardFormatListener (Hint: 2)
    - Function: CallNextHookEx (Hint: 31)
    - Function: CloseClipboard (Hint: 78)
    - Function: CreateWindowExA (Hint: 115)
    - Function: DefWindowProcA (Hint: 164)
    - Function: DispatchMessageA (Hint: 185)
    - Function: GetClipboardData (Hint: 307)
    - Function: GetDC (Hint: 319)
    - Function: GetMessageA (Hint: 380)
    - Function: GetSystemMetrics (Hint: 440)
    - Function: OpenClipboard (Hint: 637)
    - Function: PostQuitMessage (Hint: 656)
    - Function: RegisterClassExA (Hint: 697)
    - Function: ReleaseDC (Hint: 729)
    - Function: RemoveClipboardFormatListener (Hint: 731)
    - Function: SetTimer (Hint: 832)
    - Function: SetWindowsHookExA (Hint: 856)
    - Function: TranslateMessage (Hint: 897)
    - Function: UnhookWindowsHookEx (Hint: 901)
  Imported DLL: libgcc_s_seh-1.dll
    - Function: _Unwind_Resume (Hint: 15)
  Imported DLL: libstdc++-6.dll
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6substrEyy (Hint: 742)
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv (Hint: 743)
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEy (Hint: 756)
    - Function: _ZNKSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEE3strEv (Hint: 820)
    - Function: _ZNSaIcEC1Ev (Hint: 1265)
    - Function: _ZNSaIcED1Ev (Hint: 1268)
    - Function: _ZNSaIcED2Ev (Hint: 1269)
    - Function: _ZNSolsEPFRSoS_E (Hint: 1521)
    - Function: _ZNSolsEm (Hint: 1533)
    - Function: _ZNSt14basic_ofstreamIcSt11char_traitsIcEE5closeEv (Hint: 2486)
    - Function: _ZNSt14basic_ofstreamIcSt11char_traitsIcEE7is_openEv (Hint: 2487)
    - Function: _ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode (Hint: 2489)
    - Function: _ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev (Hint: 2501)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv (Hint: 3670)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEy (Hint: 3673)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcRKS3_ (Hint: 3675)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructEyc (Hint: 3678)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv (Hint: 3685)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEy (Hint: 3686)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsEPcPKcS7_ (Hint: 3689)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc (Hint: 3739)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERyy (Hint: 3769)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev (Hint: 3786)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev (Hint: 3808)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_ (Hint: 3810)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEpLEc (Hint: 3819)
    - Function: _ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEEC1Ev (Hint: 4124)
    - Function: _ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEED1Ev (Hint: 4130)
    - Function: _ZNSt8ios_base4InitC1Ev (Hint: 4392)
    - Function: _ZNSt8ios_base4InitD1Ev (Hint: 4394)
    - Function: _ZSt17__throw_bad_allocv (Hint: 4624)
    - Function: _ZSt19__throw_logic_errorPKc (Hint: 4638)
    - Function: _ZSt20__throw_length_errorPKc (Hint: 4646)
    - Function: _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_ (Hint: 4667)
    - Function: _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc (Hint: 4772)
    - Function: _ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE (Hint: 4783)
    - Function: _ZTVN10__cxxabiv117__class_type_infoE (Hint: 5369)
    - Function: _ZTVN10__cxxabiv120__si_class_type_infoE (Hint: 5373)
    - Function: _ZdlPvy (Hint: 5621)
    - Function: _Znwy (Hint: 5627)
    - Function: __cxa_begin_catch (Hint: 5637)
    - Function: __cxa_end_catch (Hint: 5642)
    - Function: __cxa_rethrow (Hint: 5653)
    - Function: __gxx_personality_seh0 (Hint: 5670)
[END IMPORTS ANALYSIS - 8 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x86 (32-bit)
[INFO] Number of sections: 4
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/rsx86.exe':
  - Section '.text': 512 bytes at offset 0x400
[+] Success: Extracted 512 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/rsx86.exe_shellcode.bin'
[INFO] SHA256: 032278948a41a5fab871449b12d17252e766195ea62a710609ac988c8a7b3a96
[INFO] Entropy: 4.6479 bits/byte

[IMPORTS ANALYSIS]
[END IMPORTS ANALYSIS - 0 DLLs imported]

[INFO] Entry point RVA: 0x14C0
[INFO] Machine type: x86 (32-bit)
[INFO] Number of sections: 17
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/norton_installer.exe':
  - Section '.text': 8704 bytes at offset 0x600
[+] Success: Extracted 8704 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/norton_installer.exe_shellcode.bin'
[INFO] SHA256: ed84b8a1ba7dbd066cc33aa802db2c23368726a8584eb6ee1a46bcf8af85a86e
[INFO] Entropy: 5.8557 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: AdjustTokenPrivileges (Hint: 1032)
    - Function: CloseServiceHandle (Hint: 1088)
    - Function: CreateServiceA (Hint: 1129)
    - Function: LookupPrivilegeValueW (Hint: 1415)
    - Function: OpenProcessToken (Hint: 1511)
    - Function: OpenSCManagerA (Hint: 1512)
    - Function: RegCloseKey (Hint: 1569)
    - Function: RegCreateKeyExW (Hint: 1578)
    - Function: RegSetValueExW (Hint: 1647)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 136)
    - Function: CreateFileW (Hint: 207)
    - Function: CreateProcessW (Hint: 233)
    - Function: CreateToolhelp32Snapshot (Hint: 256)
    - Function: DeleteCriticalSection (Hint: 277)
    - Function: EnterCriticalSection (Hint: 310)
    - Function: FreeLibrary (Hint: 433)
    - Function: GetCurrentProcess (Hint: 543)
    - Function: GetFileAttributesW (Hint: 589)
    - Function: GetLastError (Hint: 617)
    - Function: GetModuleHandleA (Hint: 637)
    - Function: GetProcAddress (Hint: 694)
    - Function: GetStartupInfoA (Hint: 729)
    - Function: InitializeCriticalSection (Hint: 877)
    - Function: LeaveCriticalSection (Hint: 973)
    - Function: LoadLibraryA (Hint: 977)
    - Function: Process32FirstW (Hint: 1085)
    - Function: Process32NextW (Hint: 1087)
    - Function: SetFileAttributesW (Hint: 1289)
    - Function: SetUnhandledExceptionFilter (Hint: 1370)
    - Function: Sleep (Hint: 1386)
    - Function: TlsGetValue (Hint: 1421)
    - Function: VirtualProtect (Hint: 1469)
    - Function: VirtualQuery (Hint: 1472)
    - Function: WaitForSingleObject (Hint: 1481)
    - Function: WriteFile (Hint: 1542)
  Imported DLL: msvcrt.dll
    - Function: __getmainargs (Hint: 58)
    - Function: __initenv (Hint: 59)
    - Function: __lconv_init (Hint: 68)
    - Function: __p__acmdln (Hint: 76)
    - Function: __p__commode (Hint: 78)
    - Function: __p__fmode (Hint: 83)
    - Function: __set_app_type (Hint: 104)
    - Function: __setusermatherr (Hint: 107)
    - Function: _amsg_exit (Hint: 142)
    - Function: _cexit (Hint: 159)
    - Function: _initterm (Hint: 338)
    - Function: _iob (Hint: 342)
    - Function: _onexit (Hint: 570)
    - Function: _wcsicmp (Hint: 798)
    - Function: abort (Hint: 922)
    - Function: calloc (Hint: 935)
    - Function: exit (Hint: 945)
    - Function: fprintf (Hint: 962)
    - Function: free (Hint: 969)
    - Function: fwrite (Hint: 982)
    - Function: malloc (Hint: 1027)
    - Function: memcpy (Hint: 1035)
    - Function: rand (Hint: 1053)
    - Function: signal (Hint: 1064)
    - Function: srand (Hint: 1070)
    - Function: strlen (Hint: 1084)
    - Function: strncmp (Hint: 1087)
    - Function: vfprintf (Hint: 1121)
    - Function: time (Hint: 713)
    - Function: wcscat_s (Hint: 1139)
    - Function: wcslen (Hint: 1147)
  Imported DLL: SHELL32.dll
    - Function: SHGetFolderPathA (Hint: 195)
    - Function: ShellExecuteExA (Hint: 305)
  Imported DLL: USER32.dll
    - Function: MessageBoxW (Hint: 596)
  Imported DLL: WINHTTP.dll
    - Function: WinHttpAddRequestHeaders (Hint: 5)
    - Function: WinHttpCloseHandle (Hint: 9)
    - Function: WinHttpConnect (Hint: 10)
    - Function: WinHttpOpen (Hint: 39)
    - Function: WinHttpOpenRequest (Hint: 40)
    - Function: WinHttpReceiveResponse (Hint: 50)
    - Function: WinHttpSendRequest (Hint: 53)
  Imported DLL: libgcc_s_dw2-1.dll
    - Function: __deregister_frame_info (Hint: 37)
    - Function: __register_frame_info (Hint: 107)
[END IMPORTS ANALYSIS - 7 DLLs imported]

[INFO] Entry point RVA: 0x14D0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x1A00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/griftygruber.exe':
  - Section '.text': 6656 bytes at offset 0x600
[+] Success: Extracted 6656 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/griftygruber.exe_shellcode.bin'
[INFO] SHA256: 884eb2ad3f33453092c19b901a6aa8391486bbc44f6dd457b99fb41d067af0f3
[INFO] Entropy: 5.8072 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: KERNEL32.dll
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetLastError (Hint: 630)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: signal (Hint: 1063)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: vfprintf (Hint: 1123)
[END IMPORTS ANALYSIS - 2 DLLs imported]

[INFO] Entry point RVA: 0x5DD60
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 6
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0xA0000
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/cutyourmeat-static.exe':
  - Section '.text': 655360 bytes at offset 0x600
[+] Success: Extracted 655360 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/cutyourmeat-static.exe_shellcode.bin'
[INFO] SHA256: e711d6c9cbc31a2bf6816b89975f35713b835214f006b4be23db982ba3399995
[INFO] Entropy: 6.1867 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 10
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x6E00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/oldgrowth.exe':
  - Section '.text': 28160 bytes at offset 0x400
[+] Success: Extracted 28160 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/oldgrowth.exe_shellcode.bin'
[INFO] SHA256: e8a6d849650f56590bee88170ba833d2143c2746eda1a3cb8b26541c51b21cf4
[INFO] Entropy: 6.2413 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExA (Hint: 1652)
    - Function: RegSetValueExA (Hint: 1681)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CreateProcessA (Hint: 234)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: FreeConsole (Hint: 440)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleFileNameA (Hint: 649)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDBCSLeadByteEx (Hint: 919)
    - Function: IsDebuggerPresent (Hint: 920)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: MultiByteToWideChar (Hint: 1036)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForSingleObject (Hint: 1503)
    - Function: WideCharToMultiByte (Hint: 1547)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: ___lc_codepage_func (Hint: 64)
    - Function: ___mb_cur_max_func (Hint: 67)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _errno (Hint: 190)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: fputc (Hint: 958)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: localeconv (Hint: 1017)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: memset (Hint: 1033)
    - Function: signal (Hint: 1063)
    - Function: strerror (Hint: 1084)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: system (Hint: 1108)
    - Function: vfprintf (Hint: 1123)
    - Function: wcslen (Hint: 1149)
  Imported DLL: WS2_32.dll
    - Function: WSACleanup (Hint: 31)
    - Function: WSAConnect (Hint: 33)
    - Function: WSASocketA (Hint: 87)
    - Function: WSAStartup (Hint: 89)
    - Function: closesocket (Hint: 164)
    - Function: htons (Hint: 180)
    - Function: inet_addr (Hint: 181)
[END IMPORTS ANALYSIS - 4 DLLs imported]

[INFO] Entry point RVA: 0x63D00
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x22D600
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/meth_adder.exe':
  - Section '.text': 2283008 bytes at offset 0x600
[+] Success: Extracted 2283008 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/meth_adder.exe_shellcode.bin'
[INFO] SHA256: f7ab441fca4b944ba9f15187c59aeee2fdc6e7987f0b200502d8d14aadeb6e7f
[INFO] Entropy: 6.1571 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 6
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x400
[INFO] Entry point is in section '.text'
[DEBUG] Processing section '.stub': RVA=0x5000, Raw=0xE00, Size=0x2000
[+] Found 2 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/obfuscated_skeeterspit.exe':
  - Section '.text': 1024 bytes at offset 0x400
  - Section '.stub': 8192 bytes at offset 0xE00
[+] Success: Extracted 9216 bytes from 2 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/obfuscated_skeeterspit.exe_shellcode.bin'
[INFO] SHA256: 7d6fc0bad5e09ebcacae62b3a09d39366b1732b741ae633ab88bfb668df7ced0
[INFO] Entropy: 0.6591 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: CloseServiceHandle (Hint: 1102)
    - Function: ControlService (Hint: 1107)
    - Function: OpenSCManagerW (Hint: 1536)
    - Function: OpenServiceW (Hint: 1538)
    - Function: QueryServiceStatus (Hint: 1593)
  Imported DLL: KERNEL32.dll
    - Function: ExitProcess (Hint: 366)
    - Function: GetCurrentProcessId (Hint: 553)
    - Function: GetProcessHeap (Hint: 716)
    - Function: GetTickCount64 (Hint: 800)
    - Function: QueryPerformanceCounter (Hint: 1131)
  Imported DLL: ntdll.dll
    - Function: RtlGetVersion (Hint: 1145)
[END IMPORTS ANALYSIS - 3 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 4
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0xA00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/cunfyoozed_rsx64.exe':
  - Section '.text': 2560 bytes at offset 0x400
[+] Success: Extracted 2560 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/cunfyoozed_rsx64.exe_shellcode.bin'
[INFO] SHA256: 5b5a72cffae36e26a0a6686c79d05cb7116db56816d6d0b001c6dc0e47470fbe
[INFO] Entropy: 2.3651 bits/byte

[IMPORTS ANALYSIS]
[END IMPORTS ANALYSIS - 0 DLLs imported]

[INFO] Entry point RVA: 0x77900
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 8
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2DCA00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/gumewurm.exe':
  - Section '.text': 3000832 bytes at offset 0x600
[+] Success: Extracted 3000832 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/gumewurm.exe_shellcode.bin'
[INFO] SHA256: 822c66f52458b4d5dd4dcefcaf8c4cf46e781e184dc48a65a96edc9abaf34288
[INFO] Entropy: 6.1999 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WerSetFlags (Hint: 0)
    - Function: WerGetFlags (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: TlsAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: RtlVirtualUnwind (Hint: 0)
    - Function: RtlLookupFunctionEntry (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: RaiseFailFastException (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: LoadLibraryExW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetErrorMode (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetCurrentThreadId (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
    - Function: AddVectoredContinueHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x63B80
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x23CA00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/3peat.exe':
  - Section '.text': 2345472 bytes at offset 0x600
[+] Success: Extracted 2345472 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/3peat.exe_shellcode.bin'
[INFO] SHA256: eefedfe6e4d20524fc86bcc3b096f1dc38da88b89002a985effbe09f54691e54
[INFO] Entropy: 6.1596 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x8A00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/shadowfall.exe':
  - Section '.text': 35328 bytes at offset 0x600
[+] Success: Extracted 35328 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/shadowfall.exe_shellcode.bin'
[INFO] SHA256: efa7031236926dcfd7a7360bceb16e3463412101adc4d82ee95bad55ad8d089a
[INFO] Entropy: 6.2193 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: AdjustTokenPrivileges (Hint: 1032)
    - Function: CloseServiceHandle (Hint: 1102)
    - Function: LookupPrivilegeValueA (Hint: 1431)
    - Function: OpenProcessToken (Hint: 1534)
    - Function: OpenSCManagerA (Hint: 1535)
    - Function: OpenServiceA (Hint: 1537)
    - Function: QueryServiceStatus (Hint: 1593)
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegCreateKeyExA (Hint: 1612)
    - Function: RegOpenKeyExA (Hint: 1652)
    - Function: RegQueryValueExA (Hint: 1665)
    - Function: RegSetValueExA (Hint: 1681)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CreateToolhelp32Snapshot (Hint: 261)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetCurrentProcess (Hint: 552)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleFileNameA (Hint: 649)
    - Function: GetProcAddress (Hint: 710)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDBCSLeadByteEx (Hint: 919)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: LoadLibraryA (Hint: 988)
    - Function: MultiByteToWideChar (Hint: 1036)
    - Function: Process32First (Hint: 1097)
    - Function: Process32Next (Hint: 1099)
    - Function: SetLastError (Hint: 1334)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualAlloc (Hint: 1486)
    - Function: VirtualFree (Hint: 1489)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WideCharToMultiByte (Hint: 1547)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: ___lc_codepage_func (Hint: 64)
    - Function: ___mb_cur_max_func (Hint: 67)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _errno (Hint: 190)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _lock (Hint: 387)
    - Function: _onexit (Hint: 553)
    - Function: _unlock (Hint: 714)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: fputc (Hint: 958)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: localeconv (Hint: 1017)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: memset (Hint: 1033)
    - Function: signal (Hint: 1063)
    - Function: strerror (Hint: 1084)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strstr (Hint: 1095)
    - Function: system (Hint: 1108)
    - Function: vfprintf (Hint: 1123)
    - Function: wcslen (Hint: 1149)
  Imported DLL: WS2_32.dll
    - Function: WSACleanup (Hint: 31)
    - Function: WSAStartup (Hint: 89)
    - Function: closesocket (Hint: 164)
    - Function: htons (Hint: 180)
    - Function: inet_pton (Hint: 184)
    - Function: sendto (Hint: 193)
    - Function: socket (Hint: 196)
  Imported DLL: libgcc_s_seh-1.dll
    - Function: _Unwind_Resume (Hint: 15)
  Imported DLL: libstdc++-6.dll
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv (Hint: 731)
    - Function: _ZNKSt7__cxx1119basic_ostringstreamIcSt11char_traitsIcESaIcEE3strEv (Hint: 828)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev (Hint: 3808)
    - Function: _ZNSt7__cxx1119basic_ostringstreamIcSt11char_traitsIcESaIcEEC1Ev (Hint: 4180)
    - Function: _ZNSt7__cxx1119basic_ostringstreamIcSt11char_traitsIcESaIcEED1Ev (Hint: 4186)
    - Function: _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc (Hint: 4772)
    - Function: _ZdaPv (Hint: 5611)
    - Function: _Znay (Hint: 5623)
    - Function: __gxx_personality_seh0 (Hint: 5670)
[END IMPORTS ANALYSIS - 6 DLLs imported]

[INFO] Entry point RVA: 0x5D660
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x8AA00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/moodup.exe':
  - Section '.text': 567808 bytes at offset 0x600
[+] Success: Extracted 567808 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/moodup.exe_shellcode.bin'
[INFO] SHA256: 11a7cbc3739783cb4abc5882532b1732acee7ea488ee42b575e9cee9e3f22cb2
[INFO] Entropy: 6.1678 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x7200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/8ball_keylogger_inject.exe':
  - Section '.text': 29184 bytes at offset 0x600
[+] Success: Extracted 29184 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/8ball_keylogger_inject.exe_shellcode.bin'
[INFO] SHA256: 99fd552463dd67c773e03275f0eeb3f8cd588f9cbaee8ca4fb00686aa02175ae
[INFO] Entropy: 6.2240 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExA (Hint: 1652)
    - Function: RegSetValueExA (Hint: 1681)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CopyFileA (Hint: 177)
    - Function: CreateDirectoryA (Hint: 190)
    - Function: CreateRemoteThread (Hint: 241)
    - Function: CreateToolhelp32Snapshot (Hint: 261)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: ExpandEnvironmentStringsA (Hint: 369)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleHandleA (Hint: 651)
    - Function: GetProcAddress (Hint: 710)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDBCSLeadByteEx (Hint: 919)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: MultiByteToWideChar (Hint: 1036)
    - Function: OpenProcess (Hint: 1069)
    - Function: Process32First (Hint: 1097)
    - Function: Process32Next (Hint: 1099)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualAllocEx (Hint: 1487)
    - Function: VirtualFreeEx (Hint: 1490)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForSingleObject (Hint: 1503)
    - Function: WideCharToMultiByte (Hint: 1547)
    - Function: WriteProcessMemory (Hint: 1576)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: ___lc_codepage_func (Hint: 64)
    - Function: ___mb_cur_max_func (Hint: 67)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _errno (Hint: 190)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _lock (Hint: 387)
    - Function: _onexit (Hint: 553)
    - Function: _unlock (Hint: 714)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: fputc (Hint: 958)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: localeconv (Hint: 1017)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: signal (Hint: 1063)
    - Function: strcmp (Hint: 1079)
    - Function: strerror (Hint: 1084)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: vfprintf (Hint: 1123)
    - Function: wcslen (Hint: 1149)
[END IMPORTS ANALYSIS - 3 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 5
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x600
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/prima_vulnus.exe':
  - Section '.text': 1536 bytes at offset 0x400
[+] Success: Extracted 1536 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/prima_vulnus.exe_shellcode.bin'
[INFO] SHA256: 7362b8ac32faa9f6381f14db159e22afa3d2186f747f21a6bfda1dd0c343490a
[INFO] Entropy: 4.2922 bits/byte

[IMPORTS ANALYSIS]
[END IMPORTS ANALYSIS - 0 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 4
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/sysutil.exe':
  - Section '.text': 512 bytes at offset 0x400
[+] Success: Extracted 512 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/sysutil.exe_shellcode.bin'
[INFO] SHA256: 526128094961cdd80a6ce5a14397d654d5c951e40b2e1c976aab821a864a85f1
[INFO] Entropy: 3.1073 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: KERNEL32.dll
    - Function: ExitProcess (Hint: 366)
    - Function: GetProcAddress (Hint: 710)
    - Function: LoadLibraryA (Hint: 988)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x7200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/keylogger_inject.exe':
  - Section '.text': 29184 bytes at offset 0x600
[+] Success: Extracted 29184 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/keylogger_inject.exe_shellcode.bin'
[INFO] SHA256: eaf0cd575b57e0488ef47825b0cda935de09bf5a3243438c47d69873c24a5901
[INFO] Entropy: 6.2286 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExA (Hint: 1652)
    - Function: RegSetValueExA (Hint: 1681)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CopyFileA (Hint: 177)
    - Function: CreateDirectoryA (Hint: 190)
    - Function: CreateRemoteThread (Hint: 241)
    - Function: CreateToolhelp32Snapshot (Hint: 261)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: ExpandEnvironmentStringsA (Hint: 369)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleHandleA (Hint: 651)
    - Function: GetProcAddress (Hint: 710)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDBCSLeadByteEx (Hint: 919)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: MultiByteToWideChar (Hint: 1036)
    - Function: OpenProcess (Hint: 1069)
    - Function: Process32First (Hint: 1097)
    - Function: Process32Next (Hint: 1099)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualAllocEx (Hint: 1487)
    - Function: VirtualFreeEx (Hint: 1490)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForSingleObject (Hint: 1503)
    - Function: WideCharToMultiByte (Hint: 1547)
    - Function: WriteProcessMemory (Hint: 1576)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: ___lc_codepage_func (Hint: 64)
    - Function: ___mb_cur_max_func (Hint: 67)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _errno (Hint: 190)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _lock (Hint: 387)
    - Function: _onexit (Hint: 553)
    - Function: _unlock (Hint: 714)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: fputc (Hint: 958)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: localeconv (Hint: 1017)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: signal (Hint: 1063)
    - Function: strcmp (Hint: 1079)
    - Function: strerror (Hint: 1084)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: vfprintf (Hint: 1123)
    - Function: wcslen (Hint: 1149)
[END IMPORTS ANALYSIS - 3 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 10
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0xAF600
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/boofer.exe':
  - Section '.text': 718336 bytes at offset 0x400
[+] Success: Extracted 718336 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/boofer.exe_shellcode.bin'
[INFO] SHA256: 9d7851c78035cb29203610bd5da38f3eb75e7d0c4fa4260847c24e2ca34ff479
[INFO] Entropy: 6.1421 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: CloseServiceHandle (Hint: 1102)
    - Function: ControlService (Hint: 1107)
    - Function: OpenSCManagerA (Hint: 1535)
    - Function: OpenServiceA (Hint: 1537)
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExA (Hint: 1652)
    - Function: RegSetValueExA (Hint: 1681)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CreateProcessA (Hint: 234)
    - Function: CreateSemaphoreW (Hint: 246)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: FreeConsole (Hint: 440)
    - Function: GetCurrentThreadId (Hint: 557)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleHandleW (Hint: 654)
    - Function: GetProcAddress (Hint: 710)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDBCSLeadByteEx (Hint: 919)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: LoadLibraryW (Hint: 991)
    - Function: MultiByteToWideChar (Hint: 1036)
    - Function: RaiseException (Hint: 1153)
    - Function: ReleaseSemaphore (Hint: 1196)
    - Function: RtlCaptureContext (Hint: 1223)
    - Function: RtlLookupFunctionEntry (Hint: 1230)
    - Function: RtlUnwindEx (Hint: 1236)
    - Function: RtlVirtualUnwind (Hint: 1237)
    - Function: SetLastError (Hint: 1334)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsAlloc (Hint: 1443)
    - Function: TlsFree (Hint: 1444)
    - Function: TlsGetValue (Hint: 1445)
    - Function: TlsSetValue (Hint: 1446)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForSingleObject (Hint: 1503)
    - Function: WideCharToMultiByte (Hint: 1547)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: ___lc_codepage_func (Hint: 64)
    - Function: ___mb_cur_max_func (Hint: 67)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _errno (Hint: 190)
    - Function: _filelengthi64 (Hint: 210)
    - Function: _fileno (Hint: 211)
    - Function: _fmode (Hint: 220)
    - Function: _fstat64 (Hint: 234)
    - Function: _initterm (Hint: 285)
    - Function: _lseeki64 (Hint: 396)
    - Function: _onexit (Hint: 553)
    - Function: _strnicmp (Hint: 658)
    - Function: _wfopen (Hint: 832)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fclose (Hint: 940)
    - Function: fflush (Hint: 943)
    - Function: fgetpos (Hint: 945)
    - Function: fopen (Hint: 953)
    - Function: fprintf (Hint: 956)
    - Function: fputc (Hint: 958)
    - Function: fputs (Hint: 959)
    - Function: fread (Hint: 962)
    - Function: free (Hint: 963)
    - Function: fsetpos (Hint: 971)
    - Function: fwrite (Hint: 976)
    - Function: getc (Hint: 980)
    - Function: getwc (Hint: 985)
    - Function: isspace (Hint: 998)
    - Function: iswctype (Hint: 1004)
    - Function: localeconv (Hint: 1017)
    - Function: malloc (Hint: 1023)
    - Function: memchr (Hint: 1029)
    - Function: memcmp (Hint: 1030)
    - Function: memcpy (Hint: 1031)
    - Function: memmove (Hint: 1032)
    - Function: memset (Hint: 1033)
    - Function: putc (Hint: 1043)
    - Function: putwc (Hint: 1046)
    - Function: realloc (Hint: 1052)
    - Function: setlocale (Hint: 1061)
    - Function: setvbuf (Hint: 1062)
    - Function: signal (Hint: 1063)
    - Function: strcmp (Hint: 1079)
    - Function: strcoll (Hint: 1080)
    - Function: strerror (Hint: 1084)
    - Function: strftime (Hint: 1085)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strxfrm (Hint: 1101)
    - Function: towlower (Hint: 1118)
    - Function: towupper (Hint: 1119)
    - Function: ungetc (Hint: 1120)
    - Function: ungetwc (Hint: 1121)
    - Function: vfprintf (Hint: 1123)
    - Function: wcscoll (Hint: 1144)
    - Function: wcsftime (Hint: 1148)
    - Function: wcslen (Hint: 1149)
    - Function: wcsxfrm (Hint: 1168)
    - Function: _write (Hint: 1212)
    - Function: _read (Hint: 1254)
    - Function: _fileno (Hint: 1281)
    - Function: _fdopen (Hint: 1285)
    - Function: _close (Hint: 1301)
  Imported DLL: WINHTTP.dll
    - Function: WinHttpAddRequestHeaders (Hint: 5)
    - Function: WinHttpCloseHandle (Hint: 9)
    - Function: WinHttpConnect (Hint: 10)
    - Function: WinHttpOpen (Hint: 39)
    - Function: WinHttpOpenRequest (Hint: 40)
    - Function: WinHttpReceiveResponse (Hint: 63)
    - Function: WinHttpSendRequest (Hint: 66)
  Imported DLL: WS2_32.dll
    - Function: WSACleanup (Hint: 31)
    - Function: WSAConnect (Hint: 33)
    - Function: WSASocketA (Hint: 87)
    - Function: WSAStartup (Hint: 89)
    - Function: WSAStringToAddressA (Hint: 90)
    - Function: closesocket (Hint: 164)
    - Function: htons (Hint: 180)
[END IMPORTS ANALYSIS - 5 DLLs imported]

[INFO] Entry point RVA: 0x5DD60
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0xA0000
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/cutyourmeat.exe':
  - Section '.text': 655360 bytes at offset 0x600
[+] Success: Extracted 655360 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/cutyourmeat.exe_shellcode.bin'
[INFO] SHA256: dc7fd5cdc0a0a7fa235c5ee10a8e637deac6f8feb8b6cbafe69313a9b3e3a549
[INFO] Entropy: 6.1866 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 10
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x340000
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/rustyklog-1b73f800be7fc83c.exe':
  - Section '.text': 3407872 bytes at offset 0x400
[+] Success: Extracted 3407872 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/rustyklog-1b73f800be7fc83c.exe_shellcode.bin'
[INFO] SHA256: 60a0434610a4c462fcf294259dec087330aca240f24214d481e9914a6acd4a78
[INFO] Entropy: 6.2957 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: KERNEL32.dll
    - Function: AddVectoredExceptionHandler (Hint: 17)
    - Function: CancelIo (Hint: 52)
    - Function: CancelIoEx (Hint: 53)
    - Function: CloseHandle (Hint: 69)
    - Function: CompareStringOrdinal (Hint: 85)
    - Function: ConnectNamedPipe (Hint: 87)
    - Function: CopyFileExW (Hint: 97)
    - Function: CreateDirectoryW (Hint: 111)
    - Function: CreateEventW (Hint: 116)
    - Function: CreateFileMappingA (Hint: 121)
    - Function: CreateFileW (Hint: 128)
    - Function: CreateHardLinkW (Hint: 132)
    - Function: CreateIoCompletionPort (Hint: 133)
    - Function: CreatePipe (Hint: 146)
    - Function: CreateProcessW (Hint: 150)
    - Function: CreateSymbolicLinkW (Hint: 160)
    - Function: CreateThread (Hint: 162)
    - Function: CreateToolhelp32Snapshot (Hint: 171)
    - Function: CreateWaitableTimerExW (Hint: 176)
    - Function: DeleteFileW (Hint: 197)
    - Function: DeleteProcThreadAttributeList (Hint: 198)
    - Function: DeviceIoControl (Hint: 208)
    - Function: DisconnectNamedPipe (Hint: 213)
    - Function: DuplicateHandle (Hint: 219)
    - Function: ExitProcess (Hint: 272)
    - Function: FileTimeToSystemTime (Hint: 281)
    - Function: FindClose (Hint: 290)
    - Function: FindFirstFileExW (Hint: 296)
    - Function: FindNextFileW (Hint: 313)
    - Function: FlushFileBuffers (Hint: 332)
    - Function: FormatMessageW (Hint: 340)
    - Function: FreeEnvironmentStringsW (Hint: 343)
    - Function: GetCommandLineW (Hint: 378)
    - Function: GetConsoleMode (Hint: 402)
    - Function: GetConsoleOutputCP (Hint: 405)
    - Function: GetConsoleScreenBufferInfo (Hint: 407)
    - Function: GetCurrentDirectoryW (Hint: 421)
    - Function: GetCurrentProcess (Hint: 427)
    - Function: GetCurrentProcessId (Hint: 428)
    - Function: GetCurrentThread (Hint: 431)
    - Function: GetCurrentThreadId (Hint: 432)
    - Function: GetEnvironmentStringsW (Hint: 455)
    - Function: GetEnvironmentVariableW (Hint: 457)
    - Function: GetExitCodeProcess (Hint: 460)
    - Function: GetFileAttributesW (Hint: 467)
    - Function: GetFileInformationByHandle (Hint: 469)
    - Function: GetFileInformationByHandleEx (Hint: 470)
    - Function: GetFileSizeEx (Hint: 474)
    - Function: GetFileType (Hint: 476)
    - Function: GetFinalPathNameByHandleW (Hint: 478)
    - Function: GetFullPathNameW (Hint: 487)
    - Function: GetLastError (Hint: 494)
    - Function: GetModuleFileNameW (Hint: 513)
    - Function: GetModuleHandleA (Hint: 514)
    - Function: GetModuleHandleW (Hint: 517)
    - Function: GetNamedPipeInfo (Hint: 527)
    - Function: GetOverlappedResult (Hint: 548)
    - Function: GetProcAddress (Hint: 570)
    - Function: GetProcessHeap (Hint: 576)
    - Function: GetProcessId (Hint: 578)
    - Function: GetQueuedCompletionStatusEx (Hint: 599)
    - Function: GetStartupInfoA (Hint: 603)
    - Function: GetStdHandle (Hint: 606)
    - Function: GetSystemDirectoryW (Hint: 620)
    - Function: GetSystemInfo (Hint: 623)
    - Function: GetSystemTimePreciseAsFileTime (Hint: 630)
    - Function: GetTempPathW (Hint: 642)
    - Function: GetWindowsDirectoryW (Hint: 689)
    - Function: HeapAlloc (Hint: 720)
    - Function: HeapFree (Hint: 724)
    - Function: HeapReAlloc (Hint: 727)
    - Function: InitOnceBeginInitialize (Hint: 735)
    - Function: InitOnceComplete (Hint: 736)
    - Function: InitializeProcThreadAttributeList (Hint: 745)
    - Function: LocalFree (Hint: 831)
    - Function: LockFileEx (Hint: 841)
    - Function: MapViewOfFile (Hint: 845)
    - Function: Module32FirstW (Hint: 850)
    - Function: Module32NextW (Hint: 852)
    - Function: MoveFileExW (Hint: 855)
    - Function: MultiByteToWideChar (Hint: 862)
    - Function: PostQueuedCompletionStatus (Hint: 902)
    - Function: QueryPerformanceCounter (Hint: 940)
    - Function: QueryPerformanceFrequency (Hint: 941)
    - Function: ReadConsoleW (Hint: 963)
    - Function: ReadFile (Hint: 966)
    - Function: ReadFileEx (Hint: 967)
    - Function: RemoveDirectoryW (Hint: 989)
    - Function: RtlCaptureContext (Hint: 1010)
    - Function: RtlLookupFunctionEntry (Hint: 1017)
    - Function: RtlVirtualUnwind (Hint: 1024)
    - Function: SetConsoleMode (Hint: 1051)
    - Function: SetConsoleTextAttribute (Hint: 1055)
    - Function: SetCurrentDirectoryW (Hint: 1062)
    - Function: SetEnvironmentVariableW (Hint: 1073)
    - Function: SetFileAttributesW (Hint: 1082)
    - Function: SetFileCompletionNotificationModes (Hint: 1084)
    - Function: SetFileInformationByHandle (Hint: 1085)
    - Function: SetFilePointerEx (Hint: 1088)
    - Function: SetFileTime (Hint: 1091)
    - Function: SetHandleInformation (Hint: 1098)
    - Function: SetLastError (Hint: 1101)
    - Function: SetThreadStackGuarantee (Hint: 1147)
    - Function: SetUnhandledExceptionFilter (Hint: 1159)
    - Function: SetWaitableTimer (Hint: 1166)
    - Function: Sleep (Hint: 1172)
    - Function: SleepEx (Hint: 1175)
    - Function: SwitchToThread (Hint: 1180)
    - Function: TerminateProcess (Hint: 1185)
    - Function: TlsAlloc (Hint: 1189)
    - Function: TlsFree (Hint: 1190)
    - Function: TlsGetValue (Hint: 1191)
    - Function: TlsSetValue (Hint: 1192)
    - Function: UnlockFile (Hint: 1204)
    - Function: UnmapViewOfFile (Hint: 1206)
    - Function: UpdateProcThreadAttribute (Hint: 1214)
    - Function: WaitForMultipleObjects (Hint: 1238)
    - Function: WaitForSingleObject (Hint: 1240)
    - Function: WideCharToMultiByte (Hint: 1267)
    - Function: WriteConsoleW (Hint: 1284)
    - Function: WriteFile (Hint: 1285)
    - Function: WriteFileEx (Hint: 1286)
  Imported DLL: USER32.dll
    - Function: CallNextHookEx (Hint: 26)
    - Function: DispatchMessageW (Hint: 159)
    - Function: GetMessageW (Hint: 331)
    - Function: SetWindowsHookExW (Hint: 692)
    - Function: TranslateMessage (Hint: 728)
  Imported DLL: advapi32.dll
    - Function: CryptAcquireContextW (Hint: 0)
    - Function: CryptDestroyKey (Hint: 0)
    - Function: CryptImportKey (Hint: 0)
    - Function: CryptReleaseContext (Hint: 0)
    - Function: RegCloseKey (Hint: 0)
    - Function: RegEnumKeyExW (Hint: 0)
    - Function: RegEnumValueW (Hint: 0)
    - Function: RegOpenKeyExW (Hint: 0)
    - Function: RegQueryInfoKeyW (Hint: 0)
    - Function: RegQueryValueExW (Hint: 0)
    - Function: SystemFunction036 (Hint: 0)
  Imported DLL: bcrypt.dll
    - Function: BCryptGenRandom (Hint: 0)
  Imported DLL: crypt32.dll
    - Function: CertAddCertificateContextToStore (Hint: 0)
    - Function: CertAddEncodedCTLToStore (Hint: 0)
    - Function: CertAddEncodedCertificateToStore (Hint: 0)
    - Function: CertCloseStore (Hint: 0)
    - Function: CertCreateCTLEntryFromCertificateContextProperties (Hint: 0)
    - Function: CertCreateCertificateContext (Hint: 0)
    - Function: CertDeleteCertificateFromStore (Hint: 0)
    - Function: CertDuplicateCertificateChain (Hint: 0)
    - Function: CertDuplicateCertificateContext (Hint: 0)
    - Function: CertDuplicateStore (Hint: 0)
    - Function: CertEnumCertificatesInStore (Hint: 0)
    - Function: CertFreeCTLContext (Hint: 0)
    - Function: CertFreeCertificateChain (Hint: 0)
    - Function: CertFreeCertificateContext (Hint: 0)
    - Function: CertGetCertificateChain (Hint: 0)
    - Function: CertGetCertificateContextProperty (Hint: 0)
    - Function: CertGetEnhancedKeyUsage (Hint: 0)
    - Function: CertOpenStore (Hint: 0)
    - Function: CertSetCertificateContextProperty (Hint: 0)
    - Function: CertVerifyCertificateChainPolicy (Hint: 0)
    - Function: CertVerifyTimeValidity (Hint: 0)
    - Function: CryptAcquireCertificatePrivateKey (Hint: 0)
    - Function: CryptBinaryToStringA (Hint: 0)
    - Function: CryptDecodeObjectEx (Hint: 0)
    - Function: CryptEncodeObjectEx (Hint: 0)
    - Function: CryptHashCertificate (Hint: 0)
    - Function: CryptMsgEncodeAndSignCTL (Hint: 0)
    - Function: CryptStringToBinaryA (Hint: 0)
    - Function: PFXExportCertStore (Hint: 0)
    - Function: PFXImportCertStore (Hint: 0)
  Imported DLL: ncrypt.dll
    - Function: NCryptFreeObject (Hint: 0)
  Imported DLL: ntdll.dll
    - Function: NtCancelIoFileEx (Hint: 0)
    - Function: NtCreateFile (Hint: 0)
    - Function: NtDeviceIoControlFile (Hint: 0)
    - Function: NtOpenFile (Hint: 0)
    - Function: NtReadFile (Hint: 0)
    - Function: NtWriteFile (Hint: 0)
    - Function: RtlNtStatusToDosError (Hint: 0)
  Imported DLL: secur32.dll
    - Function: AcceptSecurityContext (Hint: 0)
    - Function: AcquireCredentialsHandleA (Hint: 0)
    - Function: ApplyControlToken (Hint: 0)
    - Function: DecryptMessage (Hint: 0)
    - Function: DeleteSecurityContext (Hint: 0)
    - Function: EncryptMessage (Hint: 0)
    - Function: FreeContextBuffer (Hint: 0)
    - Function: FreeCredentialsHandle (Hint: 0)
    - Function: InitializeSecurityContextW (Hint: 0)
    - Function: QueryContextAttributesW (Hint: 0)
  Imported DLL: userenv.dll
    - Function: GetUserProfileDirectoryW (Hint: 0)
  Imported DLL: ws2_32.dll
    - Function: WSACleanup (Hint: 0)
    - Function: WSADuplicateSocketW (Hint: 0)
    - Function: WSAGetLastError (Hint: 0)
    - Function: WSAIoctl (Hint: 0)
    - Function: WSAPoll (Hint: 0)
    - Function: WSARecv (Hint: 0)
    - Function: WSARecvFrom (Hint: 0)
    - Function: WSASend (Hint: 0)
    - Function: WSASendMsg (Hint: 0)
    - Function: WSASendTo (Hint: 0)
    - Function: WSASocketW (Hint: 0)
    - Function: WSAStartup (Hint: 0)
    - Function: accept (Hint: 0)
    - Function: bind (Hint: 0)
    - Function: closesocket (Hint: 0)
    - Function: connect (Hint: 0)
    - Function: freeaddrinfo (Hint: 0)
    - Function: getaddrinfo (Hint: 0)
    - Function: getpeername (Hint: 0)
    - Function: getsockname (Hint: 0)
    - Function: getsockopt (Hint: 0)
    - Function: ioctlsocket (Hint: 0)
    - Function: listen (Hint: 0)
    - Function: recv (Hint: 0)
    - Function: recvfrom (Hint: 0)
    - Function: select (Hint: 0)
    - Function: send (Hint: 0)
    - Function: sendto (Hint: 0)
    - Function: setsockopt (Hint: 0)
    - Function: shutdown (Hint: 0)
    - Function: socket (Hint: 0)
  Imported DLL: api-ms-win-core-synch-l1-2-0.dll
    - Function: WaitOnAddress (Hint: 3)
    - Function: WakeByAddressAll (Hint: 1)
    - Function: WakeByAddressSingle (Hint: 2)
  Imported DLL: bcryptprimitives.dll
    - Function: ProcessPrng (Hint: 1)
  Imported DLL: KERNEL32.dll
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: RaiseException (Hint: 1153)
    - Function: RtlUnwindEx (Hint: 1236)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: __C_specific_handler (Hint: 1584)
  Imported DLL: msvcrt.dll
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _fpreset (Hint: 223)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcmp (Hint: 1030)
    - Function: memcpy (Hint: 1031)
    - Function: memmove (Hint: 1032)
    - Function: memset (Hint: 1033)
    - Function: signal (Hint: 1063)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: vfprintf (Hint: 1123)
  Imported DLL: ntdll.dll
    - Function: NtCreateNamedPipeFile (Hint: 324)
[END IMPORTS ANALYSIS - 15 DLLs imported]

[INFO] Entry point RVA: 0x75720
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 15
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x123A00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/tremble.exe':
  - Section '.text': 1194496 bytes at offset 0x600
[+] Success: Extracted 1194496 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/tremble.exe_shellcode.bin'
[INFO] SHA256: 324206b50b4f7781468bd82aadc21a7ec2145df8c66b12fa6b3f10c00c2b0519
[INFO] Entropy: 3.6023 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WerSetFlags (Hint: 0)
    - Function: WerGetFlags (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: TlsAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: RtlVirtualUnwind (Hint: 0)
    - Function: RtlLookupFunctionEntry (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: RaiseFailFastException (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: LoadLibraryExW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetErrorMode (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetCurrentThreadId (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
    - Function: AddVectoredContinueHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x4800
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/logger.exe':
  - Section '.text': 18432 bytes at offset 0x600
[+] Success: Extracted 18432 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/logger.exe_shellcode.bin'
[INFO] SHA256: baa60309f0d521ea163d8718385dad36db8a9d0ff1eebbfee436932a6eae6239
[INFO] Entropy: 5.7424 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: GDI32.dll
    - Function: BitBlt (Hint: 20)
    - Function: CreateCompatibleBitmap (Hint: 49)
    - Function: CreateCompatibleDC (Hint: 50)
    - Function: DeleteDC (Hint: 385)
    - Function: SelectObject (Hint: 870)
  Imported DLL: gdiplus.dll
    - Function: GdipAlloc (Hint: 34)
    - Function: GdipCloneImage (Hint: 55)
    - Function: GdipCreateBitmapFromHBITMAP (Hint: 78)
    - Function: GdipDisposeImage (Hint: 153)
    - Function: GdipFree (Hint: 238)
    - Function: GdipGetImageEncoders (Hint: 287)
    - Function: GdipGetImageEncodersSize (Hint: 288)
    - Function: GdipSaveImageToStream (Hint: 498)
    - Function: GdiplusShutdown (Hint: 629)
    - Function: GdiplusStartup (Hint: 630)
  Imported DLL: KERNEL32.dll
    - Function: CreateThread (Hint: 252)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleHandleA (Hint: 651)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: GlobalLock (Hint: 850)
    - Function: GlobalSize (Hint: 854)
    - Function: GlobalUnlock (Hint: 857)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: memmove (Hint: 1032)
    - Function: signal (Hint: 1063)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: vfprintf (Hint: 1123)
    - Function: wcscmp (Hint: 1143)
  Imported DLL: ole32.dll
    - Function: CreateStreamOnHGlobal (Hint: 160)
    - Function: GetHGlobalFromStream (Hint: 179)
  Imported DLL: USER32.dll
    - Function: AddClipboardFormatListener (Hint: 2)
    - Function: CallNextHookEx (Hint: 31)
    - Function: CloseClipboard (Hint: 78)
    - Function: CreateWindowExA (Hint: 115)
    - Function: DefWindowProcA (Hint: 164)
    - Function: DispatchMessageA (Hint: 185)
    - Function: GetClipboardData (Hint: 307)
    - Function: GetDC (Hint: 319)
    - Function: GetMessageA (Hint: 380)
    - Function: GetSystemMetrics (Hint: 440)
    - Function: OpenClipboard (Hint: 637)
    - Function: PostQuitMessage (Hint: 656)
    - Function: RegisterClassExA (Hint: 697)
    - Function: ReleaseDC (Hint: 729)
    - Function: RemoveClipboardFormatListener (Hint: 731)
    - Function: SetTimer (Hint: 832)
    - Function: SetWindowsHookExA (Hint: 856)
    - Function: TranslateMessage (Hint: 897)
    - Function: UnhookWindowsHookEx (Hint: 901)
  Imported DLL: libgcc_s_seh-1.dll
    - Function: _Unwind_Resume (Hint: 15)
  Imported DLL: libstdc++-6.dll
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6substrEyy (Hint: 742)
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEv (Hint: 743)
    - Function: _ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEixEy (Hint: 756)
    - Function: _ZNKSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEE3strEv (Hint: 820)
    - Function: _ZNSaIcEC1Ev (Hint: 1265)
    - Function: _ZNSaIcED1Ev (Hint: 1268)
    - Function: _ZNSaIcED2Ev (Hint: 1269)
    - Function: _ZNSolsEPFRSoS_E (Hint: 1521)
    - Function: _ZNSolsEm (Hint: 1533)
    - Function: _ZNSt14basic_ofstreamIcSt11char_traitsIcEE5closeEv (Hint: 2486)
    - Function: _ZNSt14basic_ofstreamIcSt11char_traitsIcEE7is_openEv (Hint: 2487)
    - Function: _ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode (Hint: 2489)
    - Function: _ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev (Hint: 2501)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv (Hint: 3670)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE11_M_capacityEy (Hint: 3673)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcRKS3_ (Hint: 3675)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructEyc (Hint: 3678)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv (Hint: 3685)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_set_lengthEy (Hint: 3686)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsEPcPKcS7_ (Hint: 3689)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE7_M_dataEPc (Hint: 3739)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERyy (Hint: 3769)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev (Hint: 3786)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev (Hint: 3808)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_ (Hint: 3810)
    - Function: _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEpLEc (Hint: 3819)
    - Function: _ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEEC1Ev (Hint: 4124)
    - Function: _ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEED1Ev (Hint: 4130)
    - Function: _ZNSt8ios_base4InitC1Ev (Hint: 4392)
    - Function: _ZNSt8ios_base4InitD1Ev (Hint: 4394)
    - Function: _ZSt17__throw_bad_allocv (Hint: 4624)
    - Function: _ZSt19__throw_logic_errorPKc (Hint: 4638)
    - Function: _ZSt20__throw_length_errorPKc (Hint: 4646)
    - Function: _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_ (Hint: 4667)
    - Function: _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc (Hint: 4772)
    - Function: _ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE (Hint: 4783)
    - Function: _ZTVN10__cxxabiv117__class_type_infoE (Hint: 5369)
    - Function: _ZTVN10__cxxabiv120__si_class_type_infoE (Hint: 5373)
    - Function: _ZdlPvy (Hint: 5621)
    - Function: _Znwy (Hint: 5627)
    - Function: __cxa_begin_catch (Hint: 5637)
    - Function: __cxa_end_catch (Hint: 5642)
    - Function: __cxa_rethrow (Hint: 5653)
    - Function: __gxx_personality_seh0 (Hint: 5670)
[END IMPORTS ANALYSIS - 8 DLLs imported]

[INFO] Entry point RVA: 0x60EE0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0xB5800
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/doper_c2.exe':
  - Section '.text': 743424 bytes at offset 0x600
[+] Success: Extracted 743424 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/doper_c2.exe_shellcode.bin'
[INFO] SHA256: e587cd5ea603827d3e12c6621cf6ee199b93f8adeefeadc115687f7754836b4f
[INFO] Entropy: 6.1688 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x3C6E
[INFO] Machine type: x86 (32-bit)
[INFO] Number of sections: 3
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x2000, Raw=0x200, Size=0x1E00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/module_6.exe':
  - Section '.text': 7680 bytes at offset 0x200
[+] Success: Extracted 7680 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/module_6.exe_shellcode.bin'
[INFO] SHA256: dd233ac3c07b04b6206b0ea99c5f59ee8b4f2b41819b02edfd2b92b4d1bde9de
[INFO] Entropy: 5.2248 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: mscoree.dll
    - Function: _CorExeMain (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x64060
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x25BC00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/duhmento.exe':
  - Section '.text': 2472960 bytes at offset 0x600
[+] Success: Extracted 2472960 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/duhmento.exe_shellcode.bin'
[INFO] SHA256: 245bf5c5824b0552930acbd3ab07c9e61756f4fba407b203c58dcf291e2288f2
[INFO] Entropy: 6.1546 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x1000
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 4
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/winwin.exe':
  - Section '.text': 1024 bytes at offset 0x400
[+] Success: Extracted 1024 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/winwin.exe_shellcode.bin'
[INFO] SHA256: 5e0bf49c15bee26187e787808fe2551359e639a1e52a37c832682be7250d3509
[INFO] Entropy: 3.5648 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: KERNEL32.dll
    - Function: GetProcAddress (Hint: 710)
    - Function: LoadLibraryA (Hint: 988)
  Imported DLL: USER32.dll
    - Function: CallNextHookEx (Hint: 31)
[END IMPORTS ANALYSIS - 2 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0xB0A00
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/icegaboon_coiled.exe':
  - Section '.text': 723456 bytes at offset 0x600
[+] Success: Extracted 723456 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/icegaboon_coiled.exe_shellcode.bin'
[INFO] SHA256: e7168b05f37dc587ef287bdffe27ea431c7fb467ad6aee508c61f6aa378ef52a
[INFO] Entropy: 6.1436 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: AdjustTokenPrivileges (Hint: 1032)
    - Function: ChangeServiceConfig2W (Hint: 1092)
    - Function: CloseServiceHandle (Hint: 1102)
    - Function: LookupPrivilegeValueW (Hint: 1432)
    - Function: OpenProcessToken (Hint: 1534)
    - Function: OpenSCManagerW (Hint: 1536)
    - Function: OpenServiceW (Hint: 1538)
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExW (Hint: 1653)
    - Function: RegSetValueExW (Hint: 1682)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CreateProcessW (Hint: 239)
    - Function: CreateSemaphoreW (Hint: 246)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetCurrentProcess (Hint: 552)
    - Function: GetCurrentThreadId (Hint: 557)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleFileNameW (Hint: 650)
    - Function: GetModuleHandleW (Hint: 654)
    - Function: GetProcAddress (Hint: 710)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: GetWindowsDirectoryW (Hint: 832)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDBCSLeadByteEx (Hint: 919)
    - Function: IsDebuggerPresent (Hint: 920)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: LoadLibraryW (Hint: 991)
    - Function: MultiByteToWideChar (Hint: 1036)
    - Function: RaiseException (Hint: 1153)
    - Function: ReleaseSemaphore (Hint: 1196)
    - Function: RtlCaptureContext (Hint: 1223)
    - Function: RtlLookupFunctionEntry (Hint: 1230)
    - Function: RtlUnwindEx (Hint: 1236)
    - Function: RtlVirtualUnwind (Hint: 1237)
    - Function: SetLastError (Hint: 1334)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsAlloc (Hint: 1443)
    - Function: TlsFree (Hint: 1444)
    - Function: TlsGetValue (Hint: 1445)
    - Function: TlsSetValue (Hint: 1446)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForSingleObject (Hint: 1503)
    - Function: WideCharToMultiByte (Hint: 1547)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: ___lc_codepage_func (Hint: 64)
    - Function: ___mb_cur_max_func (Hint: 67)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _errno (Hint: 190)
    - Function: _filelengthi64 (Hint: 210)
    - Function: _fileno (Hint: 211)
    - Function: _fmode (Hint: 220)
    - Function: _fstat64 (Hint: 234)
    - Function: _initterm (Hint: 285)
    - Function: _lseeki64 (Hint: 396)
    - Function: _onexit (Hint: 553)
    - Function: _strnicmp (Hint: 658)
    - Function: _wfopen (Hint: 832)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fclose (Hint: 940)
    - Function: fflush (Hint: 943)
    - Function: fgetpos (Hint: 945)
    - Function: fopen (Hint: 953)
    - Function: fprintf (Hint: 956)
    - Function: fputc (Hint: 958)
    - Function: fputs (Hint: 959)
    - Function: fread (Hint: 962)
    - Function: free (Hint: 963)
    - Function: fsetpos (Hint: 971)
    - Function: fwrite (Hint: 976)
    - Function: getc (Hint: 980)
    - Function: getwc (Hint: 985)
    - Function: isspace (Hint: 998)
    - Function: iswctype (Hint: 1004)
    - Function: localeconv (Hint: 1017)
    - Function: malloc (Hint: 1023)
    - Function: memchr (Hint: 1029)
    - Function: memcmp (Hint: 1030)
    - Function: memcpy (Hint: 1031)
    - Function: memmove (Hint: 1032)
    - Function: memset (Hint: 1033)
    - Function: putc (Hint: 1043)
    - Function: putwc (Hint: 1046)
    - Function: realloc (Hint: 1052)
    - Function: setlocale (Hint: 1061)
    - Function: setvbuf (Hint: 1062)
    - Function: signal (Hint: 1063)
    - Function: strcmp (Hint: 1079)
    - Function: strcoll (Hint: 1080)
    - Function: strerror (Hint: 1084)
    - Function: strftime (Hint: 1085)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strxfrm (Hint: 1101)
    - Function: towlower (Hint: 1118)
    - Function: towupper (Hint: 1119)
    - Function: ungetc (Hint: 1120)
    - Function: ungetwc (Hint: 1121)
    - Function: vfprintf (Hint: 1123)
    - Function: wcscat_s (Hint: 1141)
    - Function: wcscoll (Hint: 1144)
    - Function: wcsftime (Hint: 1148)
    - Function: wcslen (Hint: 1149)
    - Function: wcsxfrm (Hint: 1168)
    - Function: _write (Hint: 1212)
    - Function: _read (Hint: 1254)
    - Function: _fileno (Hint: 1281)
    - Function: _fdopen (Hint: 1285)
    - Function: _close (Hint: 1301)
  Imported DLL: ole32.dll
    - Function: CoTaskMemFree (Hint: 129)
  Imported DLL: SHELL32.dll
    - Function: SHGetKnownFolderPath (Hint: 232)
    - Function: ShellExecuteW (Hint: 340)
  Imported DLL: SHLWAPI.dll
    - Function: PathFileExistsW (Hint: 74)
  Imported DLL: USER32.dll
    - Function: FindWindowW (Hint: 273)
[END IMPORTS ANALYSIS - 7 DLLs imported]

[INFO] Entry point RVA: 0x63B80
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 13
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x400
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/cunfyoozed_3peat.exe':
  - Section '.text': 1024 bytes at offset 0x600
[+] Success: Extracted 1024 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/cunfyoozed_3peat.exe_shellcode.bin'
[INFO] SHA256: de27035b12d97df528394a41ee9ffe40c8d6b93d2bddcfe46c8ba5cd5d7e2259
[INFO] Entropy: 1.3514 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x777A0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 8
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2BB400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/uhmento_S.exe':
  - Section '.text': 2864128 bytes at offset 0x600
[+] Success: Extracted 2864128 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/uhmento_S.exe_shellcode.bin'
[INFO] SHA256: bbfb8f99f69abf730596eb3286594c8a7d5cb97996866d9e9269f9fb21d61ec3
[INFO] Entropy: 6.2094 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WerSetFlags (Hint: 0)
    - Function: WerGetFlags (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: TlsAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: RtlVirtualUnwind (Hint: 0)
    - Function: RtlLookupFunctionEntry (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: RaiseFailFastException (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: LoadLibraryExW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetErrorMode (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetCurrentThreadId (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
    - Function: AddVectoredContinueHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x62280
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 6
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x138400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/dapeton.exe':
  - Section '.text': 1278976 bytes at offset 0x400
[+] Success: Extracted 1278976 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/dapeton.exe_shellcode.bin'
[INFO] SHA256: 7abea8353fd559b220cda6befd965f433e61191f8f408193734cb35e9e61e4ad
[INFO] Entropy: 6.1886 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x7200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/dropper.exe':
  - Section '.text': 29184 bytes at offset 0x600
[+] Success: Extracted 29184 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/dropper.exe_shellcode.bin'
[INFO] SHA256: dadd43543add987b927acde38ce41c3bc74284a1e97151dad6e574443fd11fa2
[INFO] Entropy: 6.2378 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: CryptAcquireContextA (Hint: 1194)
    - Function: CryptCreateHash (Hint: 1197)
    - Function: CryptDestroyHash (Hint: 1200)
    - Function: CryptGetHashParam (Hint: 1214)
    - Function: CryptHashData (Hint: 1218)
    - Function: CryptReleaseContext (Hint: 1221)
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExA (Hint: 1652)
    - Function: RegQueryValueExA (Hint: 1665)
  Imported DLL: KERNEL32.dll
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: DeleteFileA (Hint: 285)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetLastError (Hint: 630)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: GetTempPathA (Hint: 781)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDBCSLeadByteEx (Hint: 919)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: MultiByteToWideChar (Hint: 1036)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VerSetConditionMask (Hint: 1481)
    - Function: VerifyVersionInfoA (Hint: 1484)
    - Function: VirtualAlloc (Hint: 1486)
    - Function: VirtualFree (Hint: 1489)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WideCharToMultiByte (Hint: 1547)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: ___lc_codepage_func (Hint: 64)
    - Function: ___mb_cur_max_func (Hint: 67)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _errno (Hint: 190)
    - Function: _fmode (Hint: 220)
    - Function: _ftime64 (Hint: 239)
    - Function: _initterm (Hint: 285)
    - Function: _lock (Hint: 387)
    - Function: _onexit (Hint: 553)
    - Function: _unlock (Hint: 714)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: fputc (Hint: 958)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: localeconv (Hint: 1017)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: signal (Hint: 1063)
    - Function: strerror (Hint: 1084)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: vfprintf (Hint: 1123)
    - Function: wcslen (Hint: 1149)
[END IMPORTS ANALYSIS - 3 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0xB0800
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/icegaboon_strike.exe':
  - Section '.text': 722944 bytes at offset 0x600
[+] Success: Extracted 722944 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/icegaboon_strike.exe_shellcode.bin'
[INFO] SHA256: 2f03269471db0d3831b8854249c50d3da1aa1b726db3978a070abb360fdfb1a4
[INFO] Entropy: 6.1414 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: AdjustTokenPrivileges (Hint: 1032)
    - Function: CreateProcessWithTokenW (Hint: 1142)
    - Function: DuplicateTokenEx (Hint: 1242)
    - Function: ImpersonateLoggedOnUser (Hint: 1396)
    - Function: LookupPrivilegeValueA (Hint: 1431)
    - Function: OpenProcessToken (Hint: 1534)
    - Function: RevertToSelf (Hint: 1706)
    - Function: SetThreadToken (Hint: 1757)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CreateProcessA (Hint: 234)
    - Function: CreateSemaphoreW (Hint: 246)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetCurrentProcess (Hint: 552)
    - Function: GetCurrentThreadId (Hint: 557)
    - Function: GetLastError (Hint: 630)
    - Function: GetModuleHandleW (Hint: 654)
    - Function: GetProcAddress (Hint: 710)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: IsDBCSLeadByteEx (Hint: 919)
    - Function: IsDebuggerPresent (Hint: 920)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: LoadLibraryW (Hint: 991)
    - Function: MultiByteToWideChar (Hint: 1036)
    - Function: OpenProcess (Hint: 1069)
    - Function: RaiseException (Hint: 1153)
    - Function: ReleaseSemaphore (Hint: 1196)
    - Function: RtlCaptureContext (Hint: 1223)
    - Function: RtlLookupFunctionEntry (Hint: 1230)
    - Function: RtlUnwindEx (Hint: 1236)
    - Function: RtlVirtualUnwind (Hint: 1237)
    - Function: SetLastError (Hint: 1334)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsAlloc (Hint: 1443)
    - Function: TlsFree (Hint: 1444)
    - Function: TlsGetValue (Hint: 1445)
    - Function: TlsSetValue (Hint: 1446)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForSingleObject (Hint: 1503)
    - Function: WideCharToMultiByte (Hint: 1547)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: ___lc_codepage_func (Hint: 64)
    - Function: ___mb_cur_max_func (Hint: 67)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _errno (Hint: 190)
    - Function: _filelengthi64 (Hint: 210)
    - Function: _fileno (Hint: 211)
    - Function: _fmode (Hint: 220)
    - Function: _fstat64 (Hint: 234)
    - Function: _initterm (Hint: 285)
    - Function: _lseeki64 (Hint: 396)
    - Function: _onexit (Hint: 553)
    - Function: _strnicmp (Hint: 658)
    - Function: _wfopen (Hint: 832)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fclose (Hint: 940)
    - Function: fflush (Hint: 943)
    - Function: fgetpos (Hint: 945)
    - Function: fopen (Hint: 953)
    - Function: fprintf (Hint: 956)
    - Function: fputc (Hint: 958)
    - Function: fputs (Hint: 959)
    - Function: fread (Hint: 962)
    - Function: free (Hint: 963)
    - Function: fsetpos (Hint: 971)
    - Function: fwrite (Hint: 976)
    - Function: getc (Hint: 980)
    - Function: getwc (Hint: 985)
    - Function: isspace (Hint: 998)
    - Function: iswctype (Hint: 1004)
    - Function: localeconv (Hint: 1017)
    - Function: malloc (Hint: 1023)
    - Function: memchr (Hint: 1029)
    - Function: memcmp (Hint: 1030)
    - Function: memcpy (Hint: 1031)
    - Function: memmove (Hint: 1032)
    - Function: memset (Hint: 1033)
    - Function: putc (Hint: 1043)
    - Function: putwc (Hint: 1046)
    - Function: realloc (Hint: 1052)
    - Function: setlocale (Hint: 1061)
    - Function: setvbuf (Hint: 1062)
    - Function: signal (Hint: 1063)
    - Function: strcmp (Hint: 1079)
    - Function: strcoll (Hint: 1080)
    - Function: strerror (Hint: 1084)
    - Function: strftime (Hint: 1085)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strxfrm (Hint: 1101)
    - Function: towlower (Hint: 1118)
    - Function: towupper (Hint: 1119)
    - Function: ungetc (Hint: 1120)
    - Function: ungetwc (Hint: 1121)
    - Function: vfprintf (Hint: 1123)
    - Function: wcscoll (Hint: 1144)
    - Function: wcsftime (Hint: 1148)
    - Function: wcslen (Hint: 1149)
    - Function: wcsxfrm (Hint: 1168)
    - Function: _write (Hint: 1212)
    - Function: _read (Hint: 1254)
    - Function: _fileno (Hint: 1281)
    - Function: _fdopen (Hint: 1285)
    - Function: _close (Hint: 1301)
  Imported DLL: PSAPI.DLL
    - Function: EnumProcesses (Hint: 7)
  Imported DLL: USER32.dll
    - Function: FindWindowW (Hint: 273)
[END IMPORTS ANALYSIS - 5 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/compromise_2.exe':
  - Section '.text': 8704 bytes at offset 0x600
[+] Success: Extracted 8704 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/compromise_2.exe_shellcode.bin'
[INFO] SHA256: 4c7cec408533abfd3fc438b5522627867acbce7027be6c1dca00460deb33c6e5
[INFO] Entropy: 5.9143 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: AdjustTokenPrivileges (Hint: 1032)
    - Function: CryptAcquireContextA (Hint: 1194)
    - Function: CryptCreateHash (Hint: 1197)
    - Function: CryptDecrypt (Hint: 1198)
    - Function: CryptDeriveKey (Hint: 1199)
    - Function: CryptDestroyHash (Hint: 1200)
    - Function: CryptDestroyKey (Hint: 1201)
    - Function: CryptGenRandom (Hint: 1211)
    - Function: CryptHashData (Hint: 1218)
    - Function: CryptReleaseContext (Hint: 1221)
    - Function: LookupPrivilegeValueA (Hint: 1431)
    - Function: OpenProcessToken (Hint: 1534)
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExA (Hint: 1652)
    - Function: RegQueryValueExA (Hint: 1665)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CreateThread (Hint: 252)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetCurrentProcess (Hint: 552)
    - Function: GetLastError (Hint: 630)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualAlloc (Hint: 1486)
    - Function: VirtualFree (Hint: 1489)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForSingleObject (Hint: 1503)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: _time64 (Hint: 693)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: rand (Hint: 1051)
    - Function: signal (Hint: 1063)
    - Function: srand (Hint: 1072)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strstr (Hint: 1095)
    - Function: vfprintf (Hint: 1123)
  Imported DLL: libstdc++-6.dll
    - Function: _ZdaPv (Hint: 5611)
    - Function: _Znay (Hint: 5623)
[END IMPORTS ANALYSIS - 4 DLLs imported]

[INFO] Entry point RVA: 0x14F0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2200
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/compromise_3.exe':
  - Section '.text': 8704 bytes at offset 0x600
[+] Success: Extracted 8704 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/compromise_3.exe_shellcode.bin'
[INFO] SHA256: 4c7cec408533abfd3fc438b5522627867acbce7027be6c1dca00460deb33c6e5
[INFO] Entropy: 5.9143 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: ADVAPI32.dll
    - Function: AdjustTokenPrivileges (Hint: 1032)
    - Function: CryptAcquireContextA (Hint: 1194)
    - Function: CryptCreateHash (Hint: 1197)
    - Function: CryptDecrypt (Hint: 1198)
    - Function: CryptDeriveKey (Hint: 1199)
    - Function: CryptDestroyHash (Hint: 1200)
    - Function: CryptDestroyKey (Hint: 1201)
    - Function: CryptGenRandom (Hint: 1211)
    - Function: CryptHashData (Hint: 1218)
    - Function: CryptReleaseContext (Hint: 1221)
    - Function: LookupPrivilegeValueA (Hint: 1431)
    - Function: OpenProcessToken (Hint: 1534)
    - Function: RegCloseKey (Hint: 1604)
    - Function: RegOpenKeyExA (Hint: 1652)
    - Function: RegQueryValueExA (Hint: 1665)
  Imported DLL: KERNEL32.dll
    - Function: CloseHandle (Hint: 141)
    - Function: CreateThread (Hint: 252)
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetCurrentProcess (Hint: 552)
    - Function: GetLastError (Hint: 630)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualAlloc (Hint: 1486)
    - Function: VirtualFree (Hint: 1489)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: WaitForSingleObject (Hint: 1503)
  Imported DLL: msvcrt.dll
    - Function: __C_specific_handler (Hint: 56)
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: _time64 (Hint: 693)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: rand (Hint: 1051)
    - Function: signal (Hint: 1063)
    - Function: srand (Hint: 1072)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: strstr (Hint: 1095)
    - Function: vfprintf (Hint: 1123)
  Imported DLL: libstdc++-6.dll
    - Function: _ZdaPv (Hint: 5611)
    - Function: _Znay (Hint: 5623)
[END IMPORTS ANALYSIS - 4 DLLs imported]

[INFO] Entry point RVA: 0x63B60
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 6
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x22C000
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/tsetse_static.exe':
  - Section '.text': 2277376 bytes at offset 0x600
[+] Success: Extracted 2277376 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/tsetse_static.exe_shellcode.bin'
[INFO] SHA256: 1a8418ad897c2e7ed26fdfaf5492be315143fef51a96c039c2008c14e76f38e8
[INFO] Entropy: 6.1463 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryA (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateFileA (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]

[INFO] Entry point RVA: 0x14D0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 10
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x400, Size=0x2CA800
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/modified_rustbuckit.exe':
  - Section '.text': 2926592 bytes at offset 0x400
[+] Success: Extracted 2926592 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/modified_rustbuckit.exe_shellcode.bin'
[INFO] SHA256: 47622e95a89a2d5d3364748ff3713459bf6511e90b53d8e42a80ce34c512a3a2
[INFO] Entropy: 6.3155 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: advapi32.dll
    - Function: AdjustTokenPrivileges (Hint: 26)
    - Function: CryptAcquireContextW (Hint: 95)
    - Function: CryptDestroyKey (Hint: 101)
    - Function: CryptImportKey (Hint: 120)
    - Function: CryptReleaseContext (Hint: 121)
    - Function: LookupPrivilegeValueA (Hint: 202)
  Imported DLL: crypt32.dll
    - Function: CertAddCertificateContextToStore (Hint: 5)
    - Function: CertAddEncodedCTLToStore (Hint: 8)
    - Function: CertAddEncodedCertificateToStore (Hint: 9)
    - Function: CertCloseStore (Hint: 19)
    - Function: CertCreateCTLEntryFromCertificateContextProperties (Hint: 27)
    - Function: CertCreateCertificateContext (Hint: 29)
    - Function: CertDeleteCertificateFromStore (Hint: 34)
    - Function: CertDuplicateCertificateChain (Hint: 37)
    - Function: CertDuplicateCertificateContext (Hint: 38)
    - Function: CertDuplicateStore (Hint: 39)
    - Function: CertEnumCertificatesInStore (Hint: 45)
    - Function: CertFreeCTLContext (Hint: 61)
    - Function: CertFreeCertificateChain (Hint: 62)
    - Function: CertFreeCertificateContext (Hint: 65)
    - Function: CertGetCertificateChain (Hint: 70)
    - Function: CertGetCertificateContextProperty (Hint: 71)
    - Function: CertGetEnhancedKeyUsage (Hint: 72)
    - Function: CertOpenStore (Hint: 90)
    - Function: CertSetCertificateContextProperty (Hint: 109)
    - Function: CertVerifyCertificateChainPolicy (Hint: 119)
    - Function: CertVerifyTimeValidity (Hint: 122)
    - Function: CryptAcquireCertificatePrivateKey (Hint: 124)
    - Function: CryptBinaryToStringA (Hint: 125)
    - Function: CryptDecodeObjectEx (Hint: 132)
    - Function: CryptEncodeObjectEx (Hint: 136)
    - Function: CryptHashCertificate (Hint: 158)
    - Function: CryptMsgEncodeAndSignCTL (Hint: 179)
    - Function: CryptStringToBinaryA (Hint: 202)
    - Function: PFXExportCertStore (Hint: 219)
    - Function: PFXImportCertStore (Hint: 221)
  Imported DLL: kernel32.dll
    - Function: CancelIoEx (Hint: 21)
    - Function: CloseHandle (Hint: 27)
    - Function: ConnectNamedPipe (Hint: 29)
    - Function: CreateFileW (Hint: 53)
    - Function: CreateIoCompletionPort (Hint: 58)
    - Function: CreateNamedPipeW (Hint: 61)
    - Function: DisconnectNamedPipe (Hint: 79)
    - Function: GetLastError (Hint: 193)
    - Function: GetModuleHandleA (Hint: 207)
    - Function: GetModuleHandleW (Hint: 210)
    - Function: GetNamedPipeInfo (Hint: 217)
    - Function: GetOverlappedResult (Hint: 221)
    - Function: GetProcAddress (Hint: 234)
    - Function: GetQueuedCompletionStatusEx (Hint: 247)
    - Function: LocalFree (Hint: 353)
    - Function: PostQueuedCompletionStatus (Hint: 386)
    - Function: ReadFile (Hint: 400)
    - Function: SetFileCompletionNotificationModes (Hint: 437)
    - Function: SetHandleInformation (Hint: 451)
    - Function: VirtualAllocEx (Hint: 482)
    - Function: VirtualFreeEx (Hint: 485)
    - Function: VirtualQueryEx (Hint: 490)
    - Function: WriteFile (Hint: 497)
  Imported DLL: ncrypt.dll
    - Function: NCryptFreeObject (Hint: 17)
  Imported DLL: ntdll.dll
    - Function: NtCancelIoFileEx (Hint: 9)
    - Function: NtCreateFile (Hint: 13)
    - Function: NtDeviceIoControlFile (Hint: 18)
    - Function: RtlNtStatusToDosError (Hint: 157)
  Imported DLL: secur32.dll
    - Function: AcceptSecurityContext (Hint: 1)
    - Function: AcquireCredentialsHandleA (Hint: 2)
    - Function: ApplyControlToken (Hint: 8)
    - Function: DecryptMessage (Hint: 14)
    - Function: DeleteSecurityContext (Hint: 15)
    - Function: EncryptMessage (Hint: 18)
    - Function: FreeContextBuffer (Hint: 22)
    - Function: FreeCredentialsHandle (Hint: 23)
    - Function: InitializeSecurityContextW (Hint: 35)
    - Function: QueryContextAttributesW (Hint: 49)
  Imported DLL: ws2_32.dll
    - Function: WSADuplicateSocketW (Hint: 35)
    - Function: WSAGetLastError (Hint: 42)
    - Function: WSAIoctl (Hint: 53)
    - Function: WSAPoll (Hint: 60)
    - Function: WSARecv (Hint: 63)
    - Function: WSARecvFrom (Hint: 65)
    - Function: WSASend (Hint: 68)
    - Function: WSASendMsg (Hint: 70)
    - Function: WSASendTo (Hint: 71)
    - Function: WSASocketW (Hint: 76)
    - Function: accept (Hint: 112)
    - Function: bind (Hint: 113)
    - Function: closesocket (Hint: 114)
    - Function: connect (Hint: 115)
    - Function: getpeername (Hint: 122)
    - Function: getsockname (Hint: 127)
    - Function: getsockopt (Hint: 128)
    - Function: ioctlsocket (Hint: 135)
    - Function: listen (Hint: 136)
    - Function: recv (Hint: 139)
    - Function: recvfrom (Hint: 140)
    - Function: send (Hint: 142)
    - Function: sendto (Hint: 143)
    - Function: setsockopt (Hint: 144)
    - Function: shutdown (Hint: 145)
    - Function: socket (Hint: 146)
  Imported DLL: KERNEL32.dll
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: RaiseException (Hint: 1153)
    - Function: RtlUnwindEx (Hint: 1236)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: __C_specific_handler (Hint: 1584)
  Imported DLL: msvcrt.dll
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _fpreset (Hint: 223)
    - Function: _initterm (Hint: 283)
    - Function: _onexit (Hint: 551)
    - Function: abort (Hint: 901)
    - Function: calloc (Hint: 918)
    - Function: exit (Hint: 931)
    - Function: fprintf (Hint: 951)
    - Function: free (Hint: 958)
    - Function: fwrite (Hint: 971)
    - Function: malloc (Hint: 1018)
    - Function: memcmp (Hint: 1025)
    - Function: memcpy (Hint: 1026)
    - Function: memmove (Hint: 1027)
    - Function: memset (Hint: 1028)
    - Function: signal (Hint: 1058)
    - Function: strlen (Hint: 1081)
    - Function: strncmp (Hint: 1084)
    - Function: vfprintf (Hint: 1118)
  Imported DLL: ntdll.dll
    - Function: NtCreateNamedPipeFile (Hint: 330)
  Imported DLL: advapi32.dll
    - Function: ControlService (Hint: 0)
    - Function: OpenProcessToken (Hint: 0)
    - Function: OpenSCManagerW (Hint: 0)
    - Function: OpenServiceW (Hint: 0)
    - Function: RegCloseKey (Hint: 0)
    - Function: RegEnumKeyExW (Hint: 0)
    - Function: RegEnumValueW (Hint: 0)
    - Function: RegOpenKeyExA (Hint: 0)
    - Function: RegOpenKeyExW (Hint: 0)
    - Function: RegQueryInfoKeyW (Hint: 0)
    - Function: RegQueryValueExW (Hint: 0)
    - Function: RegSetValueExA (Hint: 0)
    - Function: SystemFunction036 (Hint: 0)
  Imported DLL: bcrypt.dll
    - Function: BCryptGenRandom (Hint: 0)
  Imported DLL: kernel32.dll
    - Function: AddVectoredExceptionHandler (Hint: 0)
    - Function: CancelIo (Hint: 0)
    - Function: CompareStringOrdinal (Hint: 0)
    - Function: CopyFileExW (Hint: 0)
    - Function: CreateDirectoryW (Hint: 0)
    - Function: CreateEventW (Hint: 0)
    - Function: CreateFileMappingA (Hint: 0)
    - Function: CreateHardLinkW (Hint: 0)
    - Function: CreatePipe (Hint: 0)
    - Function: CreateProcessW (Hint: 0)
    - Function: CreateRemoteThread (Hint: 0)
    - Function: CreateSymbolicLinkW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateToolhelp32Snapshot (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: DeleteFileW (Hint: 0)
    - Function: DeleteProcThreadAttributeList (Hint: 0)
    - Function: DeviceIoControl (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: FileTimeToSystemTime (Hint: 0)
    - Function: FindClose (Hint: 0)
    - Function: FindFirstFileExW (Hint: 0)
    - Function: FindNextFileW (Hint: 0)
    - Function: FlushFileBuffers (Hint: 0)
    - Function: FormatMessageW (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: GetCommandLineW (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: GetConsoleOutputCP (Hint: 0)
    - Function: GetCurrentDirectoryW (Hint: 0)
    - Function: GetCurrentProcess (Hint: 0)
    - Function: GetCurrentProcessId (Hint: 0)
    - Function: GetCurrentThread (Hint: 0)
    - Function: GetCurrentThreadId (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetEnvironmentVariableW (Hint: 0)
    - Function: GetExitCodeProcess (Hint: 0)
    - Function: GetFileAttributesW (Hint: 0)
    - Function: GetFileInformationByHandle (Hint: 0)
    - Function: GetFileInformationByHandleEx (Hint: 0)
    - Function: GetFileSizeEx (Hint: 0)
    - Function: GetFileType (Hint: 0)
    - Function: GetFinalPathNameByHandleW (Hint: 0)
    - Function: GetFullPathNameW (Hint: 0)
    - Function: GetModuleFileNameW (Hint: 0)
    - Function: GetProcessHeap (Hint: 0)
    - Function: GetProcessId (Hint: 0)
    - Function: GetStartupInfoA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetSystemDirectoryW (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemTimePreciseAsFileTime (Hint: 0)
    - Function: GetTempPathW (Hint: 0)
    - Function: GetWindowsDirectoryW (Hint: 0)
    - Function: HeapAlloc (Hint: 0)
    - Function: HeapFree (Hint: 0)
    - Function: HeapReAlloc (Hint: 0)
    - Function: InitOnceBeginInitialize (Hint: 0)
    - Function: InitOnceComplete (Hint: 0)
    - Function: InitializeProcThreadAttributeList (Hint: 0)
    - Function: IsDebuggerPresent (Hint: 0)
    - Function: LockFileEx (Hint: 0)
    - Function: MapViewOfFile (Hint: 0)
    - Function: Module32FirstW (Hint: 0)
    - Function: Module32NextW (Hint: 0)
    - Function: MoveFileExW (Hint: 0)
    - Function: MultiByteToWideChar (Hint: 0)
    - Function: OpenProcess (Hint: 0)
    - Function: Process32First (Hint: 0)
    - Function: Process32Next (Hint: 0)
    - Function: QueryPerformanceCounter (Hint: 0)
    - Function: QueryPerformanceFrequency (Hint: 0)
    - Function: ReadConsoleW (Hint: 0)
    - Function: ReadFileEx (Hint: 0)
    - Function: RemoveDirectoryW (Hint: 0)
    - Function: RtlCaptureContext (Hint: 0)
    - Function: RtlLookupFunctionEntry (Hint: 0)
    - Function: RtlVirtualUnwind (Hint: 0)
    - Function: SetCurrentDirectoryW (Hint: 0)
    - Function: SetEnvironmentVariableW (Hint: 0)
    - Function: SetFileAttributesW (Hint: 0)
    - Function: SetFileInformationByHandle (Hint: 0)
    - Function: SetFilePointerEx (Hint: 0)
    - Function: SetFileTime (Hint: 0)
    - Function: SetLastError (Hint: 0)
    - Function: SetThreadStackGuarantee (Hint: 0)
    - Function: SetUnhandledExceptionFilter (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: Sleep (Hint: 0)
    - Function: SleepEx (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: TerminateProcess (Hint: 0)
    - Function: TlsAlloc (Hint: 0)
    - Function: TlsFree (Hint: 0)
    - Function: TlsGetValue (Hint: 0)
    - Function: TlsSetValue (Hint: 0)
    - Function: UnlockFile (Hint: 0)
    - Function: UnmapViewOfFile (Hint: 0)
    - Function: UpdateProcThreadAttribute (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: WideCharToMultiByte (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WriteFileEx (Hint: 0)
    - Function: WriteProcessMemory (Hint: 0)
  Imported DLL: ntdll.dll
    - Function: NtOpenFile (Hint: 0)
    - Function: NtReadFile (Hint: 0)
    - Function: NtWriteFile (Hint: 0)
  Imported DLL: psapi.dll
    - Function: GetProcessMemoryInfo (Hint: 0)
  Imported DLL: user32.dll
    - Function: CallNextHookEx (Hint: 0)
    - Function: GetKeyboardState (Hint: 0)
    - Function: SetWindowsHookExA (Hint: 0)
    - Function: ToUnicode (Hint: 0)
    - Function: UnhookWindowsHookEx (Hint: 0)
  Imported DLL: userenv.dll
    - Function: GetUserProfileDirectoryW (Hint: 0)
  Imported DLL: ws2_32.dll
    - Function: WSACleanup (Hint: 0)
    - Function: WSAStartup (Hint: 0)
    - Function: freeaddrinfo (Hint: 0)
    - Function: getaddrinfo (Hint: 0)
    - Function: select (Hint: 0)
  Imported DLL: api-ms-win-core-synch-l1-2-0.dll
    - Function: WaitOnAddress (Hint: 3)
    - Function: WakeByAddressAll (Hint: 1)
    - Function: WakeByAddressSingle (Hint: 2)
  Imported DLL: bcryptprimitives.dll
    - Function: ProcessPrng (Hint: 1)
[END IMPORTS ANALYSIS - 20 DLLs imported]

[INFO] Entry point RVA: 0x14D0
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 18
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2400
[INFO] Entry point is in section '.text'
[+] Found 1 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/ecliptic_hookshade.exe':
  - Section '.text': 9216 bytes at offset 0x600
[+] Success: Extracted 9216 bytes from 1 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/ecliptic_hookshade.exe_shellcode.bin'
[INFO] SHA256: 4f7279e9021905ed0578a063b625c6eceb4279c6b36b0184d3f856d9b047c6b4
[INFO] Entropy: 5.8302 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: KERNEL32.dll
    - Function: DeleteCriticalSection (Hint: 283)
    - Function: EnterCriticalSection (Hint: 319)
    - Function: GetLastError (Hint: 630)
    - Function: GetStartupInfoA (Hint: 743)
    - Function: InitializeCriticalSection (Hint: 892)
    - Function: LeaveCriticalSection (Hint: 984)
    - Function: SetUnhandledExceptionFilter (Hint: 1394)
    - Function: Sleep (Hint: 1410)
    - Function: TlsGetValue (Hint: 1445)
    - Function: VirtualProtect (Hint: 1492)
    - Function: VirtualQuery (Hint: 1494)
    - Function: __C_specific_handler (Hint: 1584)
  Imported DLL: msvcrt.dll
    - Function: __getmainargs (Hint: 82)
    - Function: __initenv (Hint: 83)
    - Function: __iob_func (Hint: 84)
    - Function: __lconv_init (Hint: 91)
    - Function: __set_app_type (Hint: 97)
    - Function: __setusermatherr (Hint: 99)
    - Function: _acmdln (Hint: 114)
    - Function: _amsg_exit (Hint: 121)
    - Function: _cexit (Hint: 139)
    - Function: _commode (Hint: 151)
    - Function: _fmode (Hint: 220)
    - Function: _initterm (Hint: 285)
    - Function: _onexit (Hint: 553)
    - Function: abort (Hint: 906)
    - Function: calloc (Hint: 923)
    - Function: exit (Hint: 936)
    - Function: fprintf (Hint: 956)
    - Function: free (Hint: 963)
    - Function: fwrite (Hint: 976)
    - Function: malloc (Hint: 1023)
    - Function: memcpy (Hint: 1031)
    - Function: signal (Hint: 1063)
    - Function: strlen (Hint: 1086)
    - Function: strncmp (Hint: 1089)
    - Function: vfprintf (Hint: 1123)
[END IMPORTS ANALYSIS - 2 DLLs imported]

[INFO] Entry point RVA: 0x77900
[INFO] Machine type: x64 (64-bit)
[INFO] Number of sections: 10
[INFO] Input file is an executable.
[DEBUG] Processing section '.text': RVA=0x1000, Raw=0x600, Size=0x2DCA00
[INFO] Entry point is in section '.text'
[DEBUG] Processing section '.stub': RVA=0x6AC000, Raw=0x651400, Size=0x2000
[+] Found 2 executable sections in '/home/mrnob0dy666/RUBBISH/BIG_EXE/modified_gumewurm.exe':
  - Section '.text': 3000832 bytes at offset 0x600
  - Section '.stub': 8192 bytes at offset 0x651400
[+] Success: Extracted 3009024 bytes from 2 sections to '/home/mrnob0dy666/RUBBISH/BIG_PURLOUT/modified_gumewurm.exe_shellcode.bin'
[INFO] SHA256: a01e66614b3a7c8b94850227ff5edff9de7632ddca229237af124f5aa2a3b29d
[INFO] Entropy: 6.2488 bits/byte

[IMPORTS ANALYSIS]
  Imported DLL: kernel32.dll
    - Function: WriteFile (Hint: 0)
    - Function: WriteConsoleW (Hint: 0)
    - Function: WerSetFlags (Hint: 0)
    - Function: WerGetFlags (Hint: 0)
    - Function: WaitForMultipleObjects (Hint: 0)
    - Function: WaitForSingleObject (Hint: 0)
    - Function: VirtualQuery (Hint: 0)
    - Function: VirtualFree (Hint: 0)
    - Function: VirtualAlloc (Hint: 0)
    - Function: TlsAlloc (Hint: 0)
    - Function: SwitchToThread (Hint: 0)
    - Function: SuspendThread (Hint: 0)
    - Function: SetWaitableTimer (Hint: 0)
    - Function: SetProcessPriorityBoost (Hint: 0)
    - Function: SetEvent (Hint: 0)
    - Function: SetErrorMode (Hint: 0)
    - Function: SetConsoleCtrlHandler (Hint: 0)
    - Function: RtlVirtualUnwind (Hint: 0)
    - Function: RtlLookupFunctionEntry (Hint: 0)
    - Function: ResumeThread (Hint: 0)
    - Function: RaiseFailFastException (Hint: 0)
    - Function: PostQueuedCompletionStatus (Hint: 0)
    - Function: LoadLibraryW (Hint: 0)
    - Function: LoadLibraryExW (Hint: 0)
    - Function: SetThreadContext (Hint: 0)
    - Function: GetThreadContext (Hint: 0)
    - Function: GetSystemInfo (Hint: 0)
    - Function: GetSystemDirectoryA (Hint: 0)
    - Function: GetStdHandle (Hint: 0)
    - Function: GetQueuedCompletionStatusEx (Hint: 0)
    - Function: GetProcessAffinityMask (Hint: 0)
    - Function: GetProcAddress (Hint: 0)
    - Function: GetErrorMode (Hint: 0)
    - Function: GetEnvironmentStringsW (Hint: 0)
    - Function: GetCurrentThreadId (Hint: 0)
    - Function: GetConsoleMode (Hint: 0)
    - Function: FreeEnvironmentStringsW (Hint: 0)
    - Function: ExitProcess (Hint: 0)
    - Function: DuplicateHandle (Hint: 0)
    - Function: CreateWaitableTimerExW (Hint: 0)
    - Function: CreateThread (Hint: 0)
    - Function: CreateIoCompletionPort (Hint: 0)
    - Function: CreateEventA (Hint: 0)
    - Function: CloseHandle (Hint: 0)
    - Function: AddVectoredExceptionHandler (Hint: 0)
    - Function: AddVectoredContinueHandler (Hint: 0)
[END IMPORTS ANALYSIS - 1 DLLs imported]


[+] Batch processing completed:
    Total files processed: 149
    Successful extractions: 142
    Failed extractions: 7
