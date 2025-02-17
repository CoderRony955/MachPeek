#include <iostream>
#include <stdbool.h>
#include <math.h>
#include <Windows.h>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <stdexcept>


#define BLUE_TXT "\033[34m"
#define RESET_TXT "\033[0m"
#define BOLD_TXT "\033[1m"
#define ITALIC_TXT "\033[3m"
#define RED_TXT "\033[31m"
#define CYAN_TXT "\033[96m"
#define CYAN_BG "\033[46m"
#define MAGENTA_TXT "\033[95m"
#define YELLOW_TXT "\033[33m"
#define GREEN_TXT "\033[92m"
#define BLACK_TXT "\033[30m"

// Function prototypes -------------
void help();
std::string welcome_txt(std::string);
void check_cpu_arch();
void check_cpu_cores();
void check_mem_pagesize();
void current_date();
void current_time();
void min_application_address();
void max_application_address();
void mem_info();
void interact();



// Functions definations ------------
void help() {
	std::string cmd1 = BLACK_TXT CYAN_BG "CCORES   : This command returns your total cores available in your CPU" RESET_TXT;
	std::string cmd2 = BLACK_TXT CYAN_BG "MEMPAGE  : This command provides infomration about your system's memory Pagesize as per your system architecture" RESET_TXT;
	std::string cmd3 = BLACK_TXT CYAN_BG "CARCH    : This command provides information about your CPU Architecture" RESET_TXT;
	std::string cmd4 = BLACK_TXT CYAN_BG "CDATE    : This command provides information about your current date" RESET_TXT;
	std::string cmd5 = BLACK_TXT CYAN_BG "CTIME    : This command provides information about your current time" RESET_TXT;
	std::string cmd6 = BLACK_TXT CYAN_BG "MAXADD   : This command returns minimum appliaction address as per your system architecture" RESET_TXT;
	std::string cmd7 = BLACK_TXT CYAN_BG "MINADD   : This command returns maximum appliaction address as per your system architecture" RESET_TXT;
	std::string cmd8 = BLACK_TXT CYAN_BG "MEMINFO  : This command retrives information abuot your system memory" RESET_TXT;
	std::string cmd9 = BLACK_TXT CYAN_BG "interact : use this command for interact with web-browsers such as open or to visit any website just entering 'open <vaildurl>' and also use to interact with your system apps such as to open apps dirsclty from CLI usinf 'open <appname>' command" RESET_TXT;
	std::string wincmds = BLUE_TXT "INFO: " RESET_TXT BLACK_TXT YELLOW_TXT "You can also run windows terimal commands" RESET_TXT;
	
	std::cout << "\n" << cmd1 << "\n" << cmd2 << "\n" << cmd3 << "\n" << cmd4 << "\n" << cmd5 << "\n" << cmd6 << "\n" << cmd7 << "\n" << cmd8 << "\n" << cmd9 << "\n" << wincmds << std::endl << std::endl;

}

std::string welcome_txt(std::string txt)
{
	return txt;
}

void check_cpu_arch() {
	SYSTEM_INFO cpuarch;
	GetSystemInfo(&cpuarch);

	switch (cpuarch.wProcessorArchitecture)
	{
	case PROCESSOR_AMD_X8664: {
		std::cout << "\n\n\033[96mYour CPU Architecture is AMD_x86-64\033[0m" << YELLOW_TXT << "and it's typically refers to the x86-64 architecture, also known as AMD64 or Intel 64.\n\n"
			"It's a 64-bit extension of the x86 instruction set architecture, originally developed by AMD but later adopted by Intel and other manufacturers.\n\n"
			"Here's a breakdown:\n\n"
			"Origin: Introduced by AMD in 1999 for their Athlon 64 processors.\n\n"
			"Key Features:\n\n"
			"- 64-bit computing: Allows the processor to handle significantly larger amounts of memory (RAM) compared to 32-bit architectures.\n\n"
			"- Backward compatibility: Can run most software designed for older 32-bit x86 processors.\n\n"
			"- Enhanced performance: Offers improved performance for memory-intensive tasks, multitasking, and applications that benefit from 64-bit addressing.\n" <<
			RESET_TXT;

		// Print the link in blue
		std::cout << BLUE_TXT << "If you want to learn more about AMD64, you can visit here: "
			"https://en.wikipedia.org/wiki/X86-64" << RESET_TXT << std::endl << std::endl;

		

		break;
	}
	case PROCESSOR_ALPHA_21064: {
		std::cout << "\n\n\033[96mYour CPU Architecture is ALPHA 21064\033[0m." << YELLOW_TXT << " PROCESSOR_ALPHA_21064 refers to a specific CPU model within Digital Equipment Corporation's (DEC) Alpha processor family. Let's break it down : \n\n"
			"Alpha: This was a 64-bit RISC (Reduced Instruction Set Computing) processor architecture developed by DEC in the early 1990s. Alpha processors were known for their high performance at the time, often competing with or exceeding the performance of contemporary RISC processors like IBM's POWER and Sun's SPARC.\n\n"
			"21064: This specific model number, often shortened to \"Alpha 21064\" or its codename \"EV4\", represents the first generation of Alpha processors. Released in 1992, the 21064 was significant for being one of the first commercially available 64-bit microprocessors. If you want learn more about ALPHA 21064 PROCESSOR ARCHITECTURE then you can visit here: " << RESET_TXT;

		std::cout << BLUE_TXT "https://en.wikipedia.org/wiki/Alpha_21064" <<  RESET_TXT << std::endl << std::endl;
		break;
	}
	case PROCESSOR_ARCHITECTURE_ALPHA: {
		std::cout << "\n\n\033[96mYour CPU Architecture is ALPHA\033[0m." << YELLOW_TXT << "PROCESSOR_ARCHITECTURE_ALPHA refers to the Alpha processor architecture, a 64 - bit RISC(Reduced Instruction Set Computing) architecture developed by Digital Equipment Corporation(DEC) in the early 1990s.Here's a summary:\n\nn64-bit from the start: Alpha was designed specifically for 64-bit computing, unlike architectures like x86 that were later extended to 64-bit.\n\nRISC philosophy: It used a smaller, simpler set of instructions compared to CISC (Complex Instruction Set Computing) architectures like x86. This often allowed for faster execution.\n\nHigh performance: Alpha processors were known for their high clock speeds and performance capabilities, competing with or surpassing other RISC architectures like IBM's POWER and Sun's SPARC at the time.\n\nPioneering features: Alpha introduced several innovations, including some of the earliest implementations of features like superscalar execution (executing multiple instructions simultaneously) and on-chip instruction and data caches.\n\nIf you want to learn more about ALPHA PROCESSOR ARCHITECTURE then you can visit here: " << RESET_TXT;

		std::cout << BLUE_TXT "https://en.wikipedia.org/wiki/DEC_Alpha" << RESET_TXT << std::endl << std::endl;
		break;
	}
	case PROCESSOR_ARCHITECTURE_ALPHA64: {
		std::cout << "\n\n\033[96mYour CPU Architecture ALPHA64\033[0m." << YELLOW_TXT << "PROCESSOR_ARCHITECTURE_ALPHA64 likely refers to the 64 - bit nature of the Alpha processor architecture.The term itself isn't a common or standardized way to refer to the architecture. Here's why : \n\nAlpha was inherently 64 - bit: Unlike architectures like x86, which started as 32 - bit and were later extended to 64 - bit(like x86 - 64 / AMD64), Alpha was designed from the ground up as a 64 - bit architecture.\n\nRedundancy in the name : The \"64\" in PROCESSOR_ARCHITECTURE_ALPHA64 is somewhat redundant because the Alpha architecture itself implies 64-bit. If you want to learn more about ALPHA64 PROCESSOR ARCHITECTURE then you can visit here: " << RESET_TXT;

		std::cout << BLUE_TXT "https://en.wikipedia.org/wiki/DEC_Alpha" <<  RESET_TXT << std::endl << std::endl;
		
		break;
	}
	case PROCESSOR_ARCHITECTURE_AMD64: {
		std::cout << "\n\n\033[96mYour CPU Architecture is AMD 64\033[0m." << YELLOW_TXT <<  "PROCESSOR_ARCHITECTURE_AMD64 typically refers to the x86 - 64 architecture, also known as AMD64 or Intel 64.\n\n"
			"It's a 64-bit extension of the x86 instruction set architecture, originally developed by AMD but later adopted by Intel and other manufacturers.\n\n"
			"Here's a breakdown:\n\n"
			"Origin: Introduced by AMD in 1999 for their Athlon 64 processors.\n\n"
			"Key Features:\n\n"
			"- 64-bit computing: Allows the processor to handle significantly larger amounts of memory (RAM) compared to 32-bit architectures.\n\n"
			"- Backward compatibility: Can run most software designed for older 32-bit x86 processors.\n\n"
			"- Enhanced performance: Offers improved performance for memory-intensive tasks, multitasking, and applications that benefit from 64-bit addressing. If you want to learn more about AMD64, you can visit here: "
			<< RESET_TXT;

		std::cout << BLUE_TXT "https://en.wikipedia.org/wiki/X86-64\n" << RESET_TXT << std::endl << std::endl;
		break;
	}
	case PROCESSOR_ARCHITECTURE_ARM: {
		std::cout << "\n\n\033[96mYour CPU Architecture is ARM\033[0m." << YELLOW_TXT << "PROCESSOR_ARCHITECTURE_ARM refers to the ARM processor architecture, a family of RISC(Reduced Instruction Set Computing) architectures widely used in embedded systems and mobile devices.Here's a summary:\n\nEnergy Efficiency: ARM architectures are known for their low power consumption, making them ideal for battery-powered devices like smartphones and tablets.\n\nRISC Design: Like Alpha, ARM employs a reduced instruction set, which can lead to simpler designs, lower power use, and potentially faster execution.\n\nScalability: ARM offers a range of processor designs from small, low-power cores for microcontrollers to high-performance cores for servers.\n\nLicensing Model:  ARM doesn't manufacture processors itself.Instead, it licenses its designs to other companies(like Apple, Samsung, Qualcomm) who then customize and manufacture the chips.If you want to learn more about ARM PROCESSOR ARCHITECTURE then you can visit here : " << RESET_TXT;

		std::cout << BLUE_TXT "https://en.wikipedia.org/wiki/ARM_architecture_family" << RESET_TXT << std::endl << std::endl;
		break;
	}
	case PROCESSOR_ARCHITECTURE_ARM64: {
		std::cout << "\n\n\033[96mYour CPU Acrchitecture is ARM64\033[0m." << YELLOW_TXT << "PROCESSOR_ARCHITECTURE_ARM64 refers to the 64 - bit version of the ARM processor architecture, also known as ARMv8 - A.Here's a summary:\n\nARMv8-A: This is the 64-bit version of the ARM architecture, introduced in 2011. It added support for 64-bit memory addressing, larger register files, and other features to improve performance and efficiency.\n\nCompatibility: ARMv8-A processors can run both 32-bit and 64-bit software, making them versatile for a wide range of applications.\n\nEnergy Efficiency: ARM64 processors retain the energy-efficient design of ARM architectures, making them popular in mobile devices, servers, and other power-sensitive applications.\n\nScalability: ARM64 processors come in a variety of configurations, from small, low-power cores to high-performance designs for servers and supercomputers. If you want to learn more about ARM64 PROCESSOR ARCHITECTURE then you can visit here: " << RESET_TXT;
		std::cout << BLUE_TXT "https://en.wikipedia.org/wiki/ARM_architecture#64/32-bit_architecture" << RESET_TXT << std::endl << std::endl;
		break;
	}
	case PROCESSOR_ARCHITECTURE_INTEL: {
		std::cout << "\n\n\033[96mYour CPU Architexture is INTEL\033[0m." << YELLOW_TXT << "PROCESSOR_ARCHITECTURE_INTEL  is a bit general since Intel produces processors based on different architectures.However, it most likely refers to processors based on Intel's x86 architecture (or its 64-bit extension, x86-64).\n\nx86 dominance:  Historically, Intel has been the primary driver of the x86 architecture, which has been the dominant architecture in personal computers and servers for decades.\n\nCommon association: When people say \"Intel processor, \" they are often referring to one based on the x86 architecture. If you want to learn more about INTEL PROCESSOR ARCHITECTURE then you can visit here: " << RESET_TXT;

		std::cout << BLUE_TXT "https://www.intel.com/content/dam/www/public/us/en/documents/white-papers/ia-introduction-basics-paper.pdf" << RESET_TXT << std::endl << std::endl;
		break;
	}
	case PROCESSOR_ARCHITECTURE_UNKNOWN: {
		std::cout << "\n\n\033[90mYour CPU Architecture is Unknown\033[0m." << YELLOW_TXT << "PROCESSOR_ARCHITECTURE_UNKNOWN indicates that the system couldn't determine the processor architecture. This could be due to various reasons, such as an unsupported processor type or an error in retrieving the information.\n\nIf you're looking for more information about your processor architecture, you may need to consult additional system resources or tools.\n\n" << RESET_TXT;
		break;
	}
	default:
		std::cout << RED_TXT "\n\nUnknown Processor Architecture\n\n" <<  RESET_TXT << std::endl << std::endl;
		break;
	}

}



void check_cpu_cores()
{
	SYSTEM_INFO cpucores;
	GetSystemInfo(&cpucores);

	DWORD CPU_CORES = cpucores.dwNumberOfProcessors;
	std::string to_str = std::to_string(CPU_CORES);
	std::cout << BLUE_TXT BOLD_TXT "\nTotal no. of cores available in your CPU: " << to_str << std::endl << std::endl;

	if (to_str == "1")
	{
		std::string dec = YELLOW_TXT ITALIC_TXT "It seems like you have a single-core processor. Single-core processors are not that powerful and are not recommended for heavy tasks or gaming. They are good for basic tasks such as browsing the internet, office work, and multitasking. It\'s better to upgrade to a multi-core processor for better performance." RESET_TXT;

		std::string more_about_cores = CYAN_TXT ITALIC_TXT "CPU cores refer to the individual processing units within a computer's central processing unit (CPU). Each core can independently execute instructions, allowing for parallel processing and improved performance, especially in multitasking environments. If you want to learn more about CPU CORES then you can visit here: " RESET_TXT;

		std::string link = BLUE_TXT "https://www.thewindowsclub.com/what-are-cpu-cores" RESET_TXT;

		std::cout << dec << std::endl << std::endl;
		std::cout << more_about_cores;
		std::cout << link << std::endl << std::endl;
	}
	else if (to_str == "2")
	{
		std::string dec_2 = YELLOW_TXT ITALIC_TXT "Your CPU is a dual-core processor. Basically dual-core processors are budget level processors and great for everyday tasks such as browsing internet, multitasking, office related work and it can handle low level gaming not much gaming such as low quality graphic games or less demanding games and it\'s provide better performacnce as comapre to single-core processors." RESET_TXT;

		std::string more_about_cores_2 = CYAN_TXT ITALIC_TXT "CPU cores refer to the individual processing units within a computer's central processing unit (CPU). Each core can independently execute instructions, allowing for parallel processing and improved performance, especially in multitasking environments. If you want to learn more about CPU CORES then you can visit here: " RESET_TXT;

		std::string link_2 = BLUE_TXT "https://www.thewindowsclub.com/what-are-cpu-cores" RESET_TXT;

		std::cout << dec_2 << std::endl << std::endl;
		std::cout << more_about_cores_2;
		std::cout << link_2 << std::endl << std::endl;
	}
	else if (to_str == "4")
	{
		std::string dec_4 = YELLOW_TXT ITALIC_TXT "Your CPU is a quad-core processor. Quad-core processors are great for multitasking, browsing and quite gaming as well as compare to dual-core processors. It can handle some modern or high demanding games and high quality graphic games as well but not at all high quality games only some of them and gaming not at only depend on the CPU it can also depend your others system hardware components. And it\'s provide better performance as compare to dual-core processors." RESET_TXT;

		std::string more_about_cores_4 = CYAN_TXT ITALIC_TXT "CPU cores refer to the individual processing units within a computer's central processing unit (CPU). Each core can independently execute instructions, allowing for parallel processing and improved performance, especially in multitasking environments. If you want to learn more about CPU CORES then you can visit here: " RESET_TXT;

		std::string link_4 = BLUE_TXT "https://www.thewindowsclub.com/what-are-cpu-cores" RESET_TXT;

		std::cout << dec_4 << std::endl << std::endl;
		std::cout << more_about_cores_4;
		std::cout << link_4 << std::endl << std::endl;
	}
	else if (to_str == "6")
	{
		std::string dec_6 = YELLOW_TXT ITALIC_TXT "Your CPU is a hexa-core processor it\'s sounds nice. Hexa-core processors well for everything at all, you can perform most them tasks such as all basic task such as Mutlitasking, Offic work, Browsing and etc. And Gaming as well as, it can handle most of them modern games with high quality graphics and high demanding games. But other heavy tasks and high end gaming also depend your other system hardware components." RESET_TXT;

		std::string more_about_cores_6 = CYAN_TXT ITALIC_TXT "CPU cores refer to the individual processing units within a computer's central processing unit (CPU). Each core can independently execute instructions, allowing for parallel processing and improved performance, especially in multitasking environments. If you want to learn more about CPU CORES then you can visit here: " RESET_TXT;

		std::string link_6 = BLUE_TXT "https://www.thewindowsclub.com/what-are-cpu-cores" RESET_TXT;

		std::cout << dec_6 << std::endl << std::endl;
		std::cout << more_about_cores_6;
		std::cout << link_6 << std::endl << std::endl;
	}
	else if (to_str == "8")
	{
		std::string dec_8 = YELLOW_TXT ITALIC_TXT "Your CPU is Octa-core processor it\'s sounds great. Octa-core processors is powerful as compare to hexa-core processors. It\'s provide great performance in most of every taks such as Multitasking, Browsing and Gaming. It can handles heavy games and high demand mdoern games much well *but gaming not at only depends on processor it\'s also depend on your system hardware components*. It\'s really great to have you Octa-core processor." RESET_TXT;

		std::string more_about_cores_8 = CYAN_TXT ITALIC_TXT "CPU cores refer to the individual processing units within a computer's central processing unit (CPU). Each core can independently execute instructions, allowing for parallel processing and improved performance, especially in multitasking environments. If you want to learn more about CPU CORES then you can visit here: " RESET_TXT;

		std::string link_8 = BLUE_TXT "https://www.thewindowsclub.com/what-are-cpu-cores" RESET_TXT;

		std::cout << dec_8 << std::endl << std::endl;
		std::cout << more_about_cores_8;
		std::cout << link_8 << std::endl << std::endl;
	}
	else
	{
		std::string dec_last = YELLOW_TXT ITALIC_TXT "It seems like you have a high-end processor with 12 cores or more :). These processors are designed for heavy tasks and high-end gaming. They can handle most of the modern games with high quality graphics and high demanding games, but gaming not only depends on the processor, it also depends on your other system hardware components. It\'s really great to have you high-end processor." RESET_TXT;

		std::string more_about_cores_ = CYAN_TXT ITALIC_TXT "CPU cores refer to the individual processing units within a computer's central processing unit (CPU). Each core can independently execute instructions, allowing for parallel processing and improved performance, especially in multitasking environments. If you want to learn more about CPU CORES then you can visit here: " RESET_TXT;

		std::string more_about_link = BLUE_TXT "https://www.thewindowsclub.com/what-are-cpu-cores" RESET_TXT;

		std::cout << dec_last << std::endl << std::endl;
		std::cout << more_about_cores_;
		std::cout << more_about_link << std::endl << std::endl;
	}


}

void check_mem_pagesize()
{
	try
	{
		SYSTEM_INFO mempagesize;
		GetSystemInfo(&mempagesize);

		std::cout << BOLD_TXT << CYAN_TXT << "\nMemory pagesize as per your system architecture: " << mempagesize.dwPageSize << 'B' << RESET_TXT << std::endl << std::endl;

	}
	catch (const std::exception& e)
	{
		std::cout << "\n" << RED_TXT << e.what() << RESET_TXT << std::endl << std::endl;

	}

	
}


void current_date()
{
	SYSTEMTIME cdate;
	GetLocalTime(&cdate);

	
	std::cout << ITALIC_TXT << BLUE_TXT << "\n" << cdate.wDay << '-' << cdate.wMonth << '-' << cdate.wYear << std::endl << std::endl;
}

void current_time()
{
	SYSTEMTIME ctime;
	GetLocalTime(&ctime);

	std::cout << ITALIC_TXT << CYAN_TXT << "\n" << ctime.wHour << RESET_TXT << std::endl << std::endl;


}


void min_application_address()
{
	try
	{
		SYSTEM_INFO minappaddress;
		GetSystemInfo(&minappaddress);

		LPVOID checkminadd = minappaddress.lpMinimumApplicationAddress;

		std::string des = BOLD_TXT  YELLOW_TXT  "An application address refers to a memory address within the virtual address space assigned to a process by the operating system. Each process in Windows runs in its own virtual address space, meaning it gets its own memory range that is isolated from other processes." RESET_TXT;

		std::cout << "\n" << CYAN_TXT << ITALIC_TXT << "minimum application address as per your architecture: " << std::showbase << std::hex << checkminadd << RESET_TXT << std::endl << std::endl;

		std::cout << "\n" << des << std::endl << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "\n" << RED_TXT << e.what() << RESET_TXT << std::endl << std::endl;
	}
	
}


void max_application_address()
{
	try
	{
		SYSTEM_INFO maxappadd;
		GetSystemInfo(&maxappadd);

		LPVOID getmaxappadd = maxappadd.lpMaximumApplicationAddress;
		std::string desc = "An application address refers to a memory address within the virtual address space assigned to a process by the operating system. Each process in Windows runs in its own virtual address space, meaning it gets its own memory range that is isolated from other processes.";

		std::cout << "\n" << CYAN_TXT << ITALIC_TXT << "max application address as per your architecture: " << std::showbase << std::hex << getmaxappadd << RESET_TXT << std::endl << std::endl;


		std::cout << "\n" << YELLOW_TXT << BOLD_TXT << desc << RESET_TXT << std::endl << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "\n" << RESET_TXT << e.what() << RESET_TXT << std::endl << std::endl;
	}
}

void mem_info()
{
	try
	{
		MEMORYSTATUSEX memInfo;
		memInfo.dwLength = sizeof(MEMORYSTATUSEX);

		if (GlobalMemoryStatusEx(&memInfo)) {
			std::cout << "\n" << "Total Physical Memory (RAM): "
				<< CYAN_TXT << std::fixed << std::setprecision(2)
				<< (double)memInfo.ullTotalPhys / (1024 * 1024 * 1024) << " GB\n" << RESET_TXT;

			std::cout << "Available Physical Memory: "
				<< YELLOW_TXT << (double)memInfo.ullAvailPhys / (1024 * 1024 * 1024) << " GB\n" << RESET_TXT;

			std::cout << "Total Virtual Memory: "
				<< BLUE_TXT << (double)memInfo.ullTotalVirtual / (1024 * 1024 * 1024) << " MB\n" << RESET_TXT;

			std::cout << "Available Virtual Memory: "
				<< GREEN_TXT << (double)memInfo.ullAvailVirtual / (1024 * 1024 * 1024) << " MB\n" << RESET_TXT << std::endl << std::endl;
		}
		else {
			std::cerr << RED_TXT << "Failed to retrieve memory information.\n" << RESET_TXT << std::endl << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "\n" << RED_TXT << e.what() << RESET_TXT << std::endl << std::endl;
	}
}

void interact()
{
	try
	{
		while (true) {
			std::string name;
			std::cout << BOLD_TXT << CYAN_TXT << "\n" << "<<..++Interact-with-apps-&-webbrowsers++..>>: ";
			std::cin >> name;

			int len;
			int slength = (int)name.length() + 1;
			len = MultiByteToWideChar(CP_ACP, 0, name.c_str(), slength, 0, 0);
			std::wstring wname(len, L'\0');
			MultiByteToWideChar(CP_ACP, 0, name.c_str(), slength, &wname[0], len);

			ShellExecute(0, L"open", wname.c_str(), 0, 0, SW_SHOWNORMAL);

			if (name == "quit")
			{
				break;
			}
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "\n" << RED_TXT << e.what() << RESET_TXT << std::endl << std::endl;
	}
}



int main()
{
	std::string cmd;
	std::string welcome_;
	welcome_ = MAGENTA_TXT " ****     ****                   **      *******                  **\n"
		"/**/ * ***/**                  /**     /**////**                /**\n"
		"/**//** ** /**  ******    ***** /**     /**   /**  *****   ***** /**  **\n"
		"/** //***  /** //////**  **///**/****** /*******  **///** **///**/** **\n"
		"/**  //*   /**  ******* /**  // /**///**/**////  /*******/*******/****\n"
		"/**   /    /** **////** /**   **/**  /**/**      /**//// /**//// /**/**\n"
		"/**        /**//********//***** /**  /**/**      //******//******/**//**\n"
		"//         //  ////////  /////  //   // //        //////  ////// //  //\n" RESET_TXT;

	std::cout << welcome_txt(welcome_) << std::endl;
	std::cout << "\nWelcome to \033[95mMachPeek\033[0m a \033[97mCommand Line Tool\033[0m to perform various tasks direclty from MachPeek CLI. There are variety of commands are available just use \033[97m'-h'\033[0m for getting informations about all available commands.\n" << std::endl;

	while (true)
	{
		std::cout << "\n" << GREEN_TXT "$$..++MachPeek++..$$: " RESET_TXT;
		std::getline(std::cin, cmd);

		if (cmd == "CCORES" || cmd == "ccores")
		{
			check_cpu_cores();
		}
		else if (cmd == "MEMPAGE" || cmd == "mempage")
		{
			check_mem_pagesize();
		}
		else if (cmd == "CARCH" || cmd == "carch")
		{
			check_cpu_arch();
		}
		else if (cmd == "CTIME" || cmd == "ctime")
		{
			current_time();
		}
		else if (cmd == "CDATE" || cmd == "cdate")
		{
			current_date();
		}
	
		else if (cmd == "-H" || cmd == "-h" || cmd == "--help")
		{
			help();
		}
		else if (cmd == "MINADD" || cmd == "minadd")
		{
			min_application_address();
		}
		else if (cmd == "MAXADD" || cmd == "maxadd")
		{
			max_application_address();
		}
		else if (cmd == "MEMINFO" || cmd == "meminfo")
		{
			mem_info();
		}
		else if (cmd == "interact" || cmd == "INTERACT")
		{

			std::string instructions = "'interact command' used for interact with web-browsers and open your system apps directly from 'MachPeek' CLI using 'open AppName' command for open your system apps directly from CLI and for open websites or to visit any web app use 'open url' with their valid URL but important note is 'URL must start with https:// e.g. https://www.xyzexample.com/, and to quit this command loop use 'quit'";

			std::cout << "\n" << YELLOW_TXT << ITALIC_TXT << instructions << RESET_TXT << std::endl << std::endl;
			interact();
		}
		else if (cmd == "exit")
		{
			break;
		}
		
		else if (!cmd.empty())
		{
			system(cmd.c_str());
		}
	
	}

	return EXIT_SUCCESS;
}