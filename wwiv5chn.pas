(* WWIV 5.x Chain File Helper *)
Unit WWIV5Chn;

Interface

Uses 
	Crt,
	Dos,
	Common;

PROCEDURE chain_init;

IMPLEMENTATION

PROCEDURE chain_init;
(* 
 * Sets up the variables and such so the chain works without 
 * WWIV 3.x running 
 *)
BEGIN
	{ TODO(Rushfan): Read chain.txt and populate this.}
	thisuser.linelen := 80;
	thisuser.pagelen := 24;
	UserOn           := true;

END;

END.