# 编译器设置
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

# 输入文件参数校验
ifndef FILE
$(error Please specify FILE="filename.cpp")
endif

# 安全文件名处理（支持任意空格和特殊字符）
EXEC := $(shell filename='$(FILE)'; \
    echo "$${filename##*/}" | sed 's/\.[^.]*$$//')

.PHONY: compile run clean help

compile: $(EXEC)

$(EXEC): $(FILE)
	@echo "Compiling $(FILE)..."
	$(CXX) $(CXXFLAGS) "$<" -o "$@"

run: compile
	@echo "Running program..."
	@./"$(EXEC)"

clean:
	@echo "Cleaning up..."
	rm -f "$(EXEC)"

help:
	@echo "Usage:"
	@echo "  make run FILE=\"文件名 包含 多个空格.cpp\""
	@echo "  make clean"
	@echo "  make help"