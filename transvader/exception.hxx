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

		void handle() const;
		void toConsole() const;
		
		/* accessor functions */
		char* getErrorString() const;
		severity_t getSeverity() const;
		char* getSeverityString() const;
};


#endif
