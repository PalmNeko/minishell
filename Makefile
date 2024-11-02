

run:
	bash scripts/run_container.sh

test:
	make -C tests/googletest/
	./tests/googletest/test.out
	pytest tests/pytest
