#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
#include <string.h>

#define BLUE_TXT "\033[34m"
#define BLACK_TXT "\033[30m"
#define ITALIC_TXT "\033[3m"
#define RED_TXT "\033[31m"
#define CYAN_BG "\033[46m"
#define CYAN_TXT "\033[36m"
#define YELLOW_TXT "\033[33m"
#define YELLOW_BG "\033[43m"
#define BOLD_TXT "\033[1m"
#define ITALIC_TXT "\033[3m"
#define RESET_TXT "\033[0m"
#define TXT_UNDERLINE "\033[3m"

void welcome_ascii_text()
{
    char* welcome_art = " **    **                          ********                  **            ****\n"
        "//**  **                          **//////   **   **        /**           /**/\n"
        "//****    ******  **   ** ******/**        //** **   ******/** *******  ******  ******\n"
        "//**    **////**/**  /**//**//*/*********  //***   **//// /**//**///**///**/  **////**\n"
        "/**   /**   /**/**  /** /** / ////////**   /**   //***** /** /**  /**  /**  /**   /**\n"
        "/**   /**   /**/**  /** /**          /**   **     /////**/** /**  /**  /**  /**   /**\n"
        "/**   //****** //******/***    ********   **      ****** /** ***  /**  /**  //******\n"
        "//     //////   ////// ///    ////////   //      //////  // ///   //   //    //////\n";

    printf(welcome_art);


}

void help() {
	char cmd1[101] = BLACK_TXT CYAN_BG "CCORES : This command provides information about your total cores availble in your CPU" RESET_TXT;
	char cmd2[101] = BLACK_TXT CYAN_BG "MPSIZE : This command provides infomration about your system Page (Computer Memory)" RESET_TXT;
	char cmd3[101] = BLACK_TXT CYAN_BG "CPUARCH : This command provides information about your CPU Architecture" RESET_TXT;
	char cmd4[101] = BLACK_TXT CYAN_BG "CDATE : This command provides information about your current date" RESET_TXT;
	char cmd5[101] = BLACK_TXT CYAN_BG "CTIME : This command provides information about your current time" RESET_TXT;
	printf("\n\n%s\n%s\n%s\n%s\n%s", cmd1, cmd2, cmd3, cmd4, cmd5);

}

void check_total_cores()
{
    SYSTEM_INFO cpucores;
    GetSystemInfo(&cpucores);

    DWORD cc = cpucores.dwNumberOfProcessors;
    char* link = CYAN_TXT "https://computercity.com/hardware/processors/cpu-cores-explained#:~:text=A%20CPU%20core%20is%20an%20independent%20processing%20unit,the%20arithmetic%20logic%20unit%20%28ALU%29%20for%20math%20operations." CYAN_TXT;
    char cc_desc[1024];
    snprintf(cc_desc, sizeof(cc_desc), YELLOW_TXT "A CPU core is the basic processing unit of a central processing unit (CPU) in a computer. Each core is capable of performing a specific task or running a program independently, allowing modern CPUs to handle multiple operations simultaneously. If you want to learn more about CPU CORES then you can visit here: %s" YELLOW_TXT, link);
    printf(BLUE_TXT ITALIC_TXT "Total no. of CPU CORES available: %lu" BLUE_TXT ITALIC_TXT, cc);
    printf("\n\n%s\n", cc_desc);

}

void memory_page_size()
{
    SYSTEM_INFO mempagesize;
    GetSystemInfo(&mempagesize);

    DWORD m_p_s = mempagesize.dwPageSize;
    char* link = CYAN_TXT "https://en.wikipedia.org/wiki/Page_%28computer_memory%29" CYAN_TXT;
    char m_p_s_desc[1024];
    snprintf(m_p_s_desc, sizeof(m_p_s_desc), YELLOW_TXT "A memory page is a fixed-length block of contiguous virtual memory (typically 4 KB) used by operating systems to manage memory allocation, enable virtual memory mapping, and optimize memory access by breaking larger memory spaces into standardized, manageable chunks that can be efficiently tracked and transferred between physical memory and storage. If you want learn more about Memory PageSize then you can visit here: %s" YELLOW_TXT, link);
    printf(CYAN_TXT ITALIC_TXT "Total memory pagesize: %lu B" CYAN_TXT ITALIC_TXT, m_p_s);
    printf("\n\n%s\n", m_p_s_desc);
}


void check_cpu_arch() {
	SYSTEM_INFO cpuarch;
	GetSystemInfo(&cpuarch);

	switch (cpuarch.wProcessorArchitecture)
	{
	case PROCESSOR_AMD_X8664: {
		printf(YELLOW_TXT "\n\nYour CPU ARCHITECTURE is \"AMD X8664\"\n\nPROCESSOR_ARCHITECTURE_AMD64 typically refers to the x86-64 architecture, also known as AMD64 or Intel 64.\n\n"
			"It's a 64-bit extension of the x86 instruction set architecture, originally developed by AMD but later adopted by Intel and other manufacturers.\n\n"
			"Here's a breakdown:\n\n"
			"Origin: Introduced by AMD in 1999 for their Athlon 64 processors.\n\n"
			"Key Features:\n\n"
			"- 64-bit computing: Allows the processor to handle significantly larger amounts of memory (RAM) compared to 32-bit architectures.\n\n"
			"- Backward compatibility: Can run most software designed for older 32-bit x86 processors.\n\n"
			"- Enhanced performance: Offers improved performance for memory-intensive tasks, multitasking, and applications that benefit from 64-bit addressing.\n\n"
			RESET_TXT);

		// Print the link in blue
		printf(BLUE_TXT "If you want to learn more about AMD64, you can visit here: "
			"https://en.wikipedia.org/wiki/X86-64\n" RESET_TXT);
		break;
	}
	case PROCESSOR_ALPHA_21064: {
		printf(YELLOW_TXT "\n\nYour CPU ARCHITECTURE is \"ALPHA 21064\"\n\nThe PROCESSOR_ALPHA_21064 refers to a specific CPU model within Digital Equipment Corporation's (DEC) Alpha processor family. Let's break it down:\n\n"
			"Alpha: This was a 64-bit RISC (Reduced Instruction Set Computing) processor architecture developed by DEC in the early 1990s. Alpha processors were known for their high performance at the time, often competing with or exceeding the performance of contemporary RISC processors like IBM's POWER and Sun's SPARC.\n\n"
			"21064: This specific model number, often shortened to \"Alpha 21064\" or its codename \"EV4\", represents the first generation of Alpha processors. Released in 1992, the 21064 was significant for being one of the first commercially available 64-bit microprocessors. If you want learn more about ALPHA 21064 PROCESSOR ARCHITECTURE then you can visit here: " RESET_TXT);

		printf(BLUE_TXT "https://en.wikipedia.org/wiki/Alpha_21064" RESET_TXT);
		break;
	}
	case PROCESSOR_ARCHITECTURE_ALPHA: {
		printf(YELLOW_TXT "\n\nPROCESSOR_ARCHITECTURE_ALPHA refers to the Alpha processor architecture, a 64-bit RISC (Reduced Instruction Set Computing) architecture developed by Digital Equipment Corporation (DEC) in the early 1990s.  Here's a summary:\n\nn64-bit from the start: Alpha was designed specifically for 64-bit computing, unlike architectures like x86 that were later extended to 64-bit.\n\nRISC philosophy: It used a smaller, simpler set of instructions compared to CISC (Complex Instruction Set Computing) architectures like x86. This often allowed for faster execution.\n\nHigh performance: Alpha processors were known for their high clock speeds and performance capabilities, competing with or surpassing other RISC architectures like IBM's POWER and Sun's SPARC at the time.\n\nPioneering features: Alpha introduced several innovations, including some of the earliest implementations of features like superscalar execution (executing multiple instructions simultaneously) and on-chip instruction and data caches.\n\nIf you want to learn more about ALPHA PROCESSOR ARCHITECTURE then you can visit here: " RESET_TXT);

		printf(BLUE_TXT "https://en.wikipedia.org/wiki/DEC_Alpha" RESET_TXT);
		break;
	}
	case PROCESSOR_ARCHITECTURE_ALPHA64: {
		printf(YELLOW_TXT "\n\nPROCESSOR_ARCHITECTURE_ALPHA64 likely refers to the 64-bit nature of the Alpha processor architecture.  The term itself isn't a common or standardized way to refer to the architecture. Here's why:\n\nAlpha was inherently 64-bit: Unlike architectures like x86, which started as 32-bit and were later extended to 64-bit (like x86-64/AMD64), Alpha was designed from the ground up as a 64-bit architecture.\n\nRedundancy in the name:  The \"64\" in PROCESSOR_ARCHITECTURE_ALPHA64 is somewhat redundant because the Alpha architecture itself implies 64-bit. If you want to learn more about ALPHA64 PROCESSOR ARCHITECTURE then you can visit here: " RESET_TXT);

		printf(BLUE_TXT "https://en.wikipedia.org/wiki/DEC_Alpha" RESET_TXT);
		break;
	}
	case PROCESSOR_ARCHITECTURE_AMD64: {
		printf(YELLOW_TXT "\n\nYour CPU ARCHITECTURE is \"AMD64\"\n\nPROCESSOR_ARCHITECTURE_AMD64 typically refers to the x86-64 architecture, also known as AMD64 or Intel 64.\n\n"
			"It's a 64-bit extension of the x86 instruction set architecture, originally developed by AMD but later adopted by Intel and other manufacturers.\n\n"
			"Here's a breakdown:\n\n"
			"Origin: Introduced by AMD in 1999 for their Athlon 64 processors.\n\n"
			"Key Features:\n\n"
			"- 64-bit computing: Allows the processor to handle significantly larger amounts of memory (RAM) compared to 32-bit architectures.\n\n"
			"- Backward compatibility: Can run most software designed for older 32-bit x86 processors.\n\n"
			"- Enhanced performance: Offers improved performance for memory-intensive tasks, multitasking, and applications that benefit from 64-bit addressing. If you want to learn more about AMD64, you can visit here: "
			RESET_TXT);

		printf(BLUE_TXT "https://en.wikipedia.org/wiki/X86-64\n" RESET_TXT);
		break;
	}
	case PROCESSOR_ARCHITECTURE_ARM: {
		printf(YELLOW_TXT "\n\nPROCESSOR_ARCHITECTURE_ARM refers to the ARM processor architecture, a family of RISC (Reduced Instruction Set Computing) architectures widely used in embedded systems and mobile devices. Here's a summary:\n\nEnergy Efficiency: ARM architectures are known for their low power consumption, making them ideal for battery-powered devices like smartphones and tablets.\n\nRISC Design: Like Alpha, ARM employs a reduced instruction set, which can lead to simpler designs, lower power use, and potentially faster execution.\n\nScalability: ARM offers a range of processor designs from small, low-power cores for microcontrollers to high-performance cores for servers.\n\nLicensing Model:  ARM doesn't manufacture processors itself. Instead, it licenses its designs to other companies (like Apple, Samsung, Qualcomm) who then customize and manufacture the chips. If you want to learn more about ARM PROCESSOR ARCHITECTURE then you can visit here: " RESET_TXT);

		printf(BLUE_TXT "https://en.wikipedia.org/wiki/ARM_architecture_family" RESET_TXT);
		break;
	}
	case PROCESSOR_ARCHITECTURE_ARM64: {
		printf(YELLOW_TXT "\n\nPROCESSOR_ARCHITECTURE_ARM64 refers to the 64-bit version of the ARM processor architecture, also known as ARMv8-A. Here's a summary:\n\nARMv8-A: This is the 64-bit version of the ARM architecture, introduced in 2011. It added support for 64-bit memory addressing, larger register files, and other features to improve performance and efficiency.\n\nCompatibility: ARMv8-A processors can run both 32-bit and 64-bit software, making them versatile for a wide range of applications.\n\nEnergy Efficiency: ARM64 processors retain the energy-efficient design of ARM architectures, making them popular in mobile devices, servers, and other power-sensitive applications.\n\nScalability: ARM64 processors come in a variety of configurations, from small, low-power cores to high-performance designs for servers and supercomputers. If you want to learn more about ARM64 PROCESSOR ARCHITECTURE then you can visit here: " RESET_TXT);
		printf(BLUE_TXT "https://en.wikipedia.org/wiki/ARM_architecture#64/32-bit_architecture" RESET_TXT);
		break;
	}
	case PROCESSOR_ARCHITECTURE_INTEL: {
		printf(YELLOW_TXT "\n\nPROCESSOR_ARCHITECTURE_INTEL  is a bit general since Intel produces processors based on different architectures. However, it most likely refers to processors based on Intel's x86 architecture (or its 64-bit extension, x86-64).\n\nx86 dominance:  Historically, Intel has been the primary driver of the x86 architecture, which has been the dominant architecture in personal computers and servers for decades.\n\nCommon association: When people say \"Intel processor, \" they are often referring to one based on the x86 architecture. If you want to learn more about INTEL PROCESSOR ARCHITECTURE then you can visit here: " RESET_TXT);

		printf(BLUE_TXT "https://www.intel.com/content/dam/www/public/us/en/documents/white-papers/ia-introduction-basics-paper.pdf" RESET_TXT);
		break;
	}
	case PROCESSOR_ARCHITECTURE_UNKNOWN: {
		printf(YELLOW_TXT "\n\nPROCESSOR_ARCHITECTURE_UNKNOWN indicates that the system couldn't determine the processor architecture. This could be due to various reasons, such as an unsupported processor type or an error in retrieving the information.\n\nIf you're looking for more information about your processor architecture, you may need to consult additional system resources or tools.\n\n" RESET_TXT);
		break;
	}
	default:
		printf(RED_TXT "\n\nUnknown Processor Architecture\n\n" RESET_TXT);
		break;
	}

}

void current_date_check() {
	SYSTEMTIME cd;
	GetLocalTime(&cd);

	printf(BOLD_TXT CYAN_TXT "Current Date: %02d/%02d/%d\n" RESET_TXT, cd.wDay, cd.wMonth, cd.wYear);
}

void current_time_check() {
	SYSTEMTIME lp;
	GetLocalTime(&lp);

	printf(BLUE_TXT "Current Time: %02d:%02d:%02d\n" RESET_TXT, lp.wHour, lp.wMinute, lp.wSecond);
}

int main()
{
    welcome_ascii_text();

    printf("\nWelcome to \033[95mYourSysInfo\033[0m a \033[97mCommand Line Tool\033[0m to get your system information. Variety of commands are available just use \033[97m'help'\033[0m for getting informations about all available commands.\n");

	bool run = true;
	while (run){

		char command[10];

		printf("\n$$Y_o_u_r_S_y_s_I_n_f_o$$: ");
		fgets(command, sizeof(command), stdin);  // Use fgets to read the input safely

		// Remove the newline character that fgets may include
		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "CCORES") == 0) {
			check_total_cores();
		}
		else if (strcmp(command, "MPSIZE") == 0) {
			memory_page_size();

		}
		else if (strcmp(command, "CPUARCH") == 0) {
			check_cpu_arch();
		}
		else if (strcmp(command, "CDATE") == 0) {
			current_date_check();
		}
		else if (strcmp(command, "CTIME") == 0) {
			current_time_check();
		}
		else if (strcmp(command, "-H") == 0) {
			help();
		}
		else if (strcmp(command, "-EXT") == 0) {
			run = false;
		}
		else {
			printf(RED_TXT "Unknown command %s ;-; want to know more about all available commands? Use '-H' for gettinf information about all available commands :) \n" RESET_TXT, command);
		}
	}

    return 0;
}