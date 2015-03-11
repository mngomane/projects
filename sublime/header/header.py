import sublime, sublime_plugin, datetime

class Makefile():
	def comment(self):
		comment = ["#**", "**#\n", "#  ", "  #\n"]
		return comment
	def body(self):
		body = (
			"OBJSDIR = bins/\n\n"
			"SRCSDIR = srcs/\n\n"
			"LIBDIR = libfts/\n\n"
			"NAME = run\n\n"
			"SRCS = main.c\n\n"
			"OBJS = $(addprefix $(OBJSDIR), $(SRCS:%.c=%.o))\n\n"
			"CXX = gcc\n\n"
			"CC = /usr/bin/clang\n\n"
			"FLAGS = -Wall -Wextra -Werror\n\n"
			"HARDCORESFLAGS = -Weverything -Wextra -Werror -Wall -pedantic-errors -std=c89\n\n"
			"LIB = -Llibfts -lfts\n\n"
			"INCS = -Iinclude -Ilibfts/include\n\n\n"
			".PHONY: all clean fclean re check\n\n"
			"all: $(OBJSDIR) $(NAME) check\n\n"
			"$(NAME): $(OBJS)\n"
			"\t@$(MAKE) -C $(LIBDIR)\n"
			"\t$(CXX) $(FLAGS) $(LIB) $(INCS) -o $(NAME) $^\n\n"
			"$(OBJSDIR):\n"
			"\tmkdir $(OBJSDIR)\n\n"
			"check: $(OBJS)\n"
			"\t@$(CC) $(HARDCORESFLAGS) $(LIB) $(INCS) -o $(NAME) $^\n\n"
			"$(OBJSDIR)%.o: $(SRCSDIR)%.c\n"
			"\t$(CXX) $(FLAGS) $(INCS) -c $< -o $@\n"
			"\t@$(CC) $(HARDCORESFLAGS) $(INCS) -c $< -o $@\n\n"
			"clean:\n"
			"\trm -rf $(OBJS)\n\n"
			"fclean: clean\n"
			"\trm -rf $(NAME)\n\n"
			"re: fclean all\n")
		return body

class HppFile():
	def comment(self):
		comment = ["/* ", " */\n", "/* ", " */\n"]
		return comment
	def body(self, fileName):
		className = fileName[:-4].capitalize();
		body = (
			"#ifndef " + fileName[:-4].upper() + "_HPP\n"
			"# define " + fileName[:-4].upper() + "_HPP\n\n"
			"# include <iostream>\n\n"
			"class " + className + " {\n"
			"private:\n"
			"\tint\t\t\t_foo;\n\n"
			"public:\n"
			"\tclass Exception : public std::exception {\n"
			"\tpublic:\n"
			"\t\tException( void ) throw();\n"
			"\t\tException( const Exception &src ) throw();\n"
			"\t\t~Exception( void ) throw();\n\n"
			"\t\tvirtual const char\t*message( void ) const throw();\n"
			"\t};\n"
			"\t" + className + "( void );\n"
			"\t" + className + "( const int n );\n"
			"\t" + className + "( const " + className + " &src );\n"
			"\t~" + className + "( void );\n\n"
			"\tstatic int\tstatic_var;\n"
			"\t" + className + "\t\t&operator=( const " + className + " &rhs );\n"
			"\tint\t\t\tgetFoo( void ) const;\n"
			"};\n"
			"std::ostream\t&operator<<( std::ostream &lhs, const " + className + " &rhs );\n\n"
			"#endif\n")
		return body

class HFile():
	def comment(self):
		comment = ["/* ", " */\n", "/* ", " */\n"]
		return comment
	def body(self, fileName):
		body = (
			"#ifndef " + fileName[:-2].upper() + "_H\n"
			"# define " + fileName[:-2].upper() + "_H\n\n"
			"#endif\n")
		return body

class MainCpp():
	def comment(self):
		comment = ["/* ", " */\n", "/* ", " */\n"]
		return comment
	def body(self):
		body = (
			"int\t\tmain( void )\n"
			"{\n"
			"\treturn 0;\n"
			"}\n")
		return body

class MainC():
	def comment(self):
		comment = ["/* ", " */\n", "/* ", " */\n"]
		return comment
	def body(self):
		body = (
			"int\t\tmain(void)\n"
			"{\n"
			"\treturn (0);\n"
			"}\n")
		return body

class SFile():
	def comment(self):
		comment = ["; *", "* ;\n", ";  ", "  ;\n"]
		return comment
	def body(self, fileName):
		body = (
			"section\t\t.bss\n"
			"\ttmp:\tresq\t1\n\n"
			"section\t\t.data\n"
			"\tdebug_string:\tdb\t\t\"Debug\", 0ah\n"
			"\t.len:\t\t\tequ\t\t$ - debug_string\n\n"
			"section\t\t.text\n"
			"\tglobal\t_" + fileName[:-2] + "\n\n"
			"_" + fileName[:-2] + ":\n\n"
			"_clear:\n"
			"\tret\n")
		return body

class ASMFile():
	def comment(self):
		comment = ["; *", "* ;\n", ";  ", "  ;\n"]
		return comment
	def body(self, fileName):
		body = (
			"section\t\t.bss\n"
			"\ttmp:\tresq\t1\n\n"
			"section\t\t.data\n"
			"\tdebug_string:\tdb\t\t\"Debug\", 0ah\n"
			"\t.len:\t\t\tequ\t\t$ - debug_string\n\n"
			"section\t\t.text\n"
			"\tglobal\t_" + fileName[:-4] + "\n\n"
			"_" + fileName[:-4] + ":\n\n"
			"_clear:\n"
			"\tret\n")
		return body

class CppFile():
	def comment(self):
		comment = ["/* ", " */\n", "/* ", " */\n"]
		return comment
	def body(self, fileName):
		className = fileName[:-4].capitalize();
		body = (
			"#include \"" + fileName[:-4] + ".hpp\"\n\n"
			"int\t\t\t\t" + className + "::static_var = 0;\n\n" +
			className +"::Exception::Exception( void ) throw()\n"
			"{\n"
			"\tstd::cerr << \"Default Exception Constructor called\" << std::endl;\n"
			"}\n\n" +
			className +"::Exception::Exception( const "+ className + "::Exception &src ) throw()\n"
			"{\n"
			"\tstd::cerr << \"Copy Exception Constructor called\" << std::endl;\n"
			"\t*this = src;\n"
			"}\n\n" +
			className +"::Exception::~Exception( void ) throw()\n"
			"{\n"
			"\tstd::cerr << \"Exception Destructor called\" << std::endl;\n"
			"}\n\n"
			"const char\t\t*" + className + "::Exception::message( void ) const throw()\n"
			"{\n"
			"\treturn (\"Ouch, there is an exception\");\n"
			"}\n\n" +
			className + "::" + className + "( void ) : _foo( 0 )\n"
			"{\n"
			"\tstd::cout << \"Default Constructor called\" << std::endl;\n"
			"}\n\n" +
			className + "::" + className + "( const int n ) : _foo( n )\n"
			"{\n"
			"\tstd::cout << \"Parametric Constructor called\" << std::endl;\n"
			"\ttry {\n"
			"\t\tif ( n < 0 ) {\n"
			"\t\t\tthrow " + className + "::Exception();\n"
			"\t\t};\n"
			"\t} catch ( " + className + "::Exception &e ) {\n"
			"\t\tstd::cerr << e.message() << std::endl;\n"
			"\t} catch (...) {\n"
			"\t\tstd::cerr << \"Error, unknown exception!\" << std::endl;\n"
			"\t}\n"
			"}\n\n" +
			className + "::" + className + "( const " + className + " &src )\n"
			"{\n"
			"\tstd::cout << \"Copy Constructor called\" << std::endl;\n"
			"\t*this = src;\n"
			"}\n\n" +
			className + "::~" + className + "( void )\n"
			"{\n"
			"\tstd::cout << \"Destructor called\" << std::endl;\n"
			"}\n\n" +
			"int\t\t\t\t" + className + "::getFoo( void ) const\n"
			"{\n"
			"\treturn this->_foo;\n"
			"}\n\n" +
			className + "\t\t\t&" + className + "::operator=( const " + className + " &rhs )\n"
			"{\n"
			"\tstd::cout << \"Assignment operator called\" << std::endl;\n"
			"\tif ( this != &rhs ) {\n"
			"\t\tthis->_foo = rhs.getFoo();\n"
			"\t}\n"
			"\treturn *this;\n"
			"}\n\n"
			"std::ostream\t&operator<<( std::ostream &lhs, const " + className + " &rhs )\n"
			"{\n"
			"\tlhs << \"The value of _foo is : \" << rhs.getFoo();\n"
			"\treturn lhs;\n"
			"}\n")
		return body

class CFile():
	def comment(self):
		comment = ["/* ", " */\n", "/* ", " */\n"]
		return comment
	def body(self, fileName):
		body = (
			"#include \"" + fileName[:-2] + ".h\"\n\n")
		return body

class JlFile():
	def comment(self):
		comment = ["#**", "**#\n", "#  ", "  #\n"]
		return comment
	def body(self, fileName):
		body = ""
		return body

class HeaderCommand(sublime_plugin.TextCommand):
	def run(self, edit):
		def getHeader(fileName, comment):
			header = (
				comment[0] + "**************************************************************************" + comment[1] +
				comment[2] + "                                                                          " + comment[3] +
				comment[2] + "                                                       :::      ::::::::  " + comment[3] +
				comment[2] + "  " + fileName + " " * (51 - len(fileName)) + ":+:      :+:    :+:  " + comment[3] +
				comment[2] + "                                                   +:+ +:+         +:+    " + comment[3] +
				comment[2] + "  By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+       " + comment[3] +
				comment[2] + "                                               +#+#+#+#+#+   +#+          " + comment[3] +
				comment[2] + "  Created: " + str(datetime.datetime.now().strftime('%Y/%m/%d %H:%M:%S')) +
				" by mngomane          #+#    #+#            " + comment[3] +
				comment[2] + "  Updated: " + str(datetime.datetime.now().strftime('%Y/%m/%d %H:%M:%S')) +
				" by mngomane         ###   ########.fr      " + comment[3] +
				comment[2] + "                                                                          " + comment[3] +
				comment[0] + "**************************************************************************" + comment[1] + "\n")
			return header
		def getFileName(self):
			fullFileName = self.view.file_name()
			nameSplit = fullFileName.rsplit("/", 1) if fullFileName else None
			fileName = nameSplit[1] if (fullFileName and len(nameSplit) > 1) else str(fullFileName)
			fileName = str(fileName) if len(str(fileName)) < 51 else "..." + str(fileName)[-45:]
			return fileName
		fileName = getFileName(self)
		if fileName == "Makefile":
			comment = Makefile().comment()
			body = Makefile().body()
		elif fileName[-4:] == ".hpp":
			comment = HppFile().comment()
			body = HppFile().body(fileName)
		elif fileName[-2:] == ".h":
			comment = HFile().comment()
			body = HFile().body(fileName)
		elif fileName == "main.cpp":
			comment = MainCpp().comment()
			body = MainCpp().body()
		elif fileName == "main.c":
			comment = MainC().comment()
			body = MainC().body()
		elif fileName[-2:] == ".s":
			comment = SFile().comment()
			body = SFile().body(fileName)
		elif fileName[-4:] == ".asm":
			comment = ASMFile().comment()
			body = ASMFile().body(fileName)
		elif fileName[-4:] == ".cpp":
			comment = CppFile().comment()
			body = CppFile().body(fileName)
		elif fileName[-2:] == ".c":
			comment = CFile().comment()
			body = CFile().body(fileName)
		elif fileName[-3:] == ".jl":
			comment = JlFile().comment()
			body = JlFile().body(fileName)
		else:
			comment = ["#**", "**#\n", "#  ", "  #\n"]
			body = ""
		if fileName == "auteur":
			skeleton = "mngomane\n"
		else:
			skeleton = getHeader(fileName, comment) + body
		self.view.insert(
			edit,
			0, 
			skeleton)
