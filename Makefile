LATEXCMD = pdflatex -shell-escape -output-directory build/
export max_print_line = 1048576

help:
	@echo "This makefile builds your Competitive Programming Library"
	@echo ""
	@echo "Available commands are:"
	@echo "    make fast        - to build the notebook quickly (only runs LaTeX once)"
	@echo "    make notebook    - to build the notebook fully (runs twice for TOC)"
	@echo "    make clean       - to clean up the build directory and minted cache"
	@echo "    make veryclean   - to clean up and remove the final PDF"
	@echo "    make help        - to show this information"

fast: | build
	$(LATEXCMD) main.tex </dev/null
	cp build/main.pdf notebook.pdf

notebook: | build
	$(LATEXCMD) main.tex && $(LATEXCMD) main.tex
	cp build/main.pdf notebook.pdf

clean:
	rm -rf build/
	rm -rf _minted-*/
	rm -f *.aux *.log *.toc *.out *.fls *.fdb_latexmk *.minted main.pdf

veryclean: clean
	rm -f notebook.pdf

.PHONY: help fast notebook clean veryclean

build:
	mkdir -p build/
