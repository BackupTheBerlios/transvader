#ifndef EXCEPTION_HXX
#define EXCEPTION_HXX

typedef enum
{
	ERR_FATAL,
	ERR_ERROR,
	ERR_WARNING
} severity_t;


class Exception
{
	private:
		char* error;
		severity_t severity;
	
	public:
		Exception ( const char* error = "Unknown Error",
			const severity_t severity = ERR_FATAL );
		~Exception();

		void handle();
		void toConsole();
		
		/* accessor functions */
		char* getErrorString();
		severity_t getSeverity();
		char* getSeverityString();
};


#endif
