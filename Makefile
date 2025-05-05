# 编译器设置
CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra

# 输入文件参数校验
ifndef FILE
$(error Please specify FILE="filename.cpp")
endif

# 带空格文件名处理（兼容所有POSIX shell）
EXEC := $(shell echo '$(FILE)' | xargs basename | sed 's/\.[^.]*$$//')

.PHONY: compile run clean help

compile: $(EXEC)

$(EXEC): $(FILE)
	@echo "Compiling $(FILE)..."
	$(CXX) $(CXXFLAGS) "$<" -o $@

run: compile
	@echo "Running program..."
	./$(EXEC)

clean:
	@echo "Cleaning up..."
	rm -f $(EXEC)

help:
	@echo "Usage:"
	@echo "  make run FILE=\"100571B. Troynacci Query.cpp\""
	@echo "  make clean"
	@echo "  make help"