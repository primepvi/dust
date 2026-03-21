.PHONY: all engine sandbox clean compile

all: engine sandbox

engine:
	$(MAKE) -C engine

sandbox: engine
	$(MAKE) -C sandbox

clean:
	$(MAKE) -C engine clean
	$(MAKE) -C sandbox clean
	rm -f compile_commands.json

compile:
	$(MAKE) clean
	bear -- $(MAKE) all
