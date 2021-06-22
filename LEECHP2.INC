procedure lbulle;
var q:text;
begin
  if nc=1 then
    begin
      cls;
      ansic(3);
      if thisuser.sl < 255 then
        sysoplog('Played LEECH! today');
    end;
  assign(q,gfilespath+'bulletin.lch');
  {$I-} reset(q); {$I+}
  if ioresult<>0 then print('No LLL bulletin today.') else begin
   close(q);
   print('');
   printfile(gfilespath+'bulletin.lch');
   end;
   pausescr;
end;


procedure wbulle;
var filvar:text; ii:integer; li:array[1..4] of astr;
begin
  nl;print('Enter four lines:'); nl;
  for ii:=1 to 4 do begin
    prt(cstr(ii)+':'); inputl(li[ii],75);
  end;
  prompt('Is this okay? ');
  if yn then begin
    assign(filvar,gfilespath+'bulletin.lch');
    {$I-} rewrite(filvar); {$I+}
    writeln(filvar,'LLL bulletin announced by:  '+mn_name);
    writeln(filvar,'');
    for ii:=1 to 4 do writeln(filvar,li[ii]);
    close(filvar); print('Bulletin saved.');
  end else prompt('Nothing saved.');
end;


procedure bulle;
var q:text;
begin
 cj:='?';
 repeat
   nl;
   if cj='?' then begin
     cls;
     print('The LLL Bulletin:');
     print('');
     print('Options: ');
     print(' [L] Listen to bulletin');
     print(' [W] Write Bulletin');
     print(' [Q] Quit');
   end;
   nl;
   prt('Which (L,W,Q,?) : '); onek(cj,'QLW?');
   case cj of
     'L':lbulle;
     'W':wbulle;
   end;
 until (cj='Q') or hangup;
end;


procedure armlist;
begin
  cls;
  printfile(gfilespath+'armor.lch');
end;


procedure lokarm;
begin
  if gg=1 then begin
          yomama:='None'; fv:=0; fu:=1; fc:='0';
         end;
  if gg=2 then begin
          yomama:='Punch Cards'; fv:=100; fu:=2; fc:='100';
         end;
  if gg=3 then begin
          yomama:='Paper Strips'; fv:=200; fu:=3; fc:='200';
         end;
  if gg=4 then begin
          yomama:='Floppy disk'; fv:=400; fu:=4; fc:='400';
         end;
  if gg=5 then begin
          yomama:='High density floppy'; fv:=800; fu:=5; fc:='800';
         end;
  if gg=6 then begin
          yomama:='Tape Backup'; fv:=2000; fu:=7; fc:='2,000';
         end;
  if gg=7 then begin
          yomama:='Long Tape Backup'; fv:=4000; fu:=8; fc:='4,000';
         end;
  if gg=8 then begin
          yomama:='Elephant'; fv:=8000; fu:=9; fc:='8,000';
     end;
  if gg=9 then begin
          yomama:='Duplicate computer'; fv:=20000; fu:=11; fc:='20,000';
     end;
  if gg=10 then begin
          yomama:='Duplicate computer w/lock'; fv:=(4.0000000000E+04); fu:=12; fc:='40,000';
     end;
  if gg=11 then begin
          yomama:='Federal protection'; fv:=(8.0000000000E+04); fu:=13; fc:='80,000';
     end;
  if gg=12 then begin
          yomama:='World protection'; fv:=(2.0000000000E+05); fu:=15; fc:='200,000';
     end;
  if gg=13 then begin
          yomama:='Teenager to busy out line'; fv:=(4.0000000000E+05); fu:=16; fc:='400,000';
     end;
  if gg=14 then begin
          yomama:='Read-only attribute on megs'; fv:=(8.0000000000E+05); fu:=17; fc:='800,000';
     end;
  if gg=15 then begin
          yomama:='All of the above protections'; fv:=(2.0000000000E+06); fu:=20; fc:='2,000,000';
     end;
end;



procedure weplist;
begin
  cls;
  printfile(gfilespath+'weapon.lch');
end;



procedure lokwep;
begin
  if gg=1 then begin
          yomama:='Dumb Terminal'; fv:=0; fu:=1; fc:='0';
         end;
  if gg=2 then begin
          yomama:='Turbo-Term'; fv:=100; fu:=2; fc:='100';
         end;
  if gg=3 then begin
          yomama:='Smart Comm'; fv:=200; fu:=3; fc:='200';
         end;
  if gg=4 then begin
          yomama:='QModem SST'; fv:=400; fu:=4; fc:='400';
         end;
  if gg=5 then begin
          yomama:='Procomm'; fv:=800; fu:=5; fc:='800';
         end;
  if gg=6 then begin
          yomama:='Hacker''s Delight'; fv:=2000; fu:=7; fc:='2,000';
         end;
  if gg=7 then begin
          yomama:='Trojan Generator'; fv:=4000; fu:=8; fc:='4,000';
         end;
  if gg=8 then begin
          yomama:='ANSI Porno picture'; fv:=8000; fu:=9; fc:='8,000';
     end;
  if gg=9 then begin
          yomama:='Dumb Comm'; fv:=20000; fu:=11; fc:='20,000';
     end;
  if gg=10 then begin
          yomama:='Keyboard Locker'; fv:=(4.0000000000E+04); fu:=12; fc:='40,000';
     end;
  if gg=11 then begin
          yomama:='Ascii Express'; fv:=(8.0000000000E+04); fu:=13; fc:='80,000';
     end;
  if gg=12 then begin
          yomama:='Proterm'; fv:=(2.0000000000E+05); fu:=15; fc:='200,000';
     end;
  if gg=13 then begin
          yomama:='WWIV terminal program (yeah!)'; fv:=(4.0000000000E+05); fu:=16; fc:='400,000';
     end;
  if gg=14 then begin
          yomama:='Super Deleter'; fv:=(8.0000000000E+05); fu:=17; fc:='800,000';
     end;
  if gg=15 then begin
          yomama:='WipeOut Comm'; fv:=(2.0000000000E+06); fu:=20; fc:='2,000,000';
     end;
end;


procedure barm;
VAR whwe:astr; gt:integer; prmon:real;
begin
  gt:=0;
  armlist;
  print('');
 repeat
  prt('Enter number of backup you wish to buy:  '); input(whwe,2);
  gg:=value(whwe);
 until (gg<=15) or hangup;
 if gg>=1 then begin
  gt:=1;
  cls;
  lokarm;
  print('A '+yomama+' costs $'+fc+'.');
  prt('Do you wish to purchase it? '); onek(cj,'YN');
  case cj of
   'Y':begin
         if fv>mn_mon then print('That price is over your savings!');
         if fv<=mn_mon then begin
          ansic(7);
          print('Backup bought.');
          ansic(0);
          mn_arm:=yomama;
          mn_arms:=fu;
          prmon:=mn_mon;
          mn_mon:=mn_mon-fv;
          if prmon<>(mn_mon+fv) then mn_mon:=mn_mon+1;
         end;
       end;
   'N':print('Aborted.');
   end;
  end;
  if gt=0 then print('Aborted.');
end;


procedure sarm;
var sdol:real; armor:astr;
begin
  cls;
  if mn_arms=1 then sdol:=0;
  if mn_arms=2 then sdol:=50;
  if mn_arms=3 then sdol:=100;
  if mn_arms=4 then sdol:=200;
  if mn_arms=5 then sdol:=400;
  if mn_arms=7 then sdol:=1000;
  if mn_arms=8 then sdol:=2000;
  if mn_arms=9 then sdol:=4000;
  if mn_arms=11 then sdol:=10000;
  if mn_arms=12 then sdol:=2.0000000000E+04;
  if mn_arms=13 then sdol:=4.0000000000E+04;
  if mn_arms=15 then sdol:=1.0000000000E+05;
  if mn_arms=16 then sdol:=2.0000000000E+05;
  if mn_arms=17 then sdol:=4.0000000000E+05;
  if mn_arms=20 then sdol:=1.0000000000E+06;
  str(sdol:1:0,armor);
  print('You can sell your '+mn_arm+' for $'+armor);
  prt('Do you wish to do so?'); onek(cj,'YN');
  case cj of
    'Y':begin
          print('Backup Sold.');
          mn_mon:=mn_mon+(sdol);
          mn_arm:='None';
          mn_arms:=1;
        end;
    'N':print('Aborted.');
  end;
end;


procedure bwep;
VAR whwe:astr; gt:integer; prmon:real;
begin
  gt:=0;
  weplist;
  print('');
 repeat
  prt('Enter number of software you wish to buy:  '); input(whwe,2);
  gg:=value(whwe);
 until (gg<=15) or hangup;
 if gg>=1 then begin
  gt:=1;
  cls;
  lokwep;
  print('A '+yomama+' costs $'+fc+'.');
  prt('Do you wish to purchase it? '); onek(cj,'YN');
  case cj of
   'Y':begin
         if fv>mn_mon then print('That price is over your savings!');
         if fv<=mn_mon then begin
          ansic(7);
          print('Software bought.');
          ansic(0);
          mn_wep:=yomama;
          mn_weps:=fu;
          prmon:=mn_mon;
          mn_mon:=mn_mon-fv;
          if prmon<>(mn_mon+fv) then mn_mon:=mn_mon+1;
         end;
       end;
   'N':print('Aborted.');
   end;
  end;
  if gt=0 then print('Aborted.');
end;


procedure swep;
var sdol:real; weapon:astr;
begin
  cls;
  if mn_weps=1 then sdol:=0;
  if mn_weps=2 then sdol:=50;
  if mn_weps=3 then sdol:=100;
  if mn_weps=4 then sdol:=200;
  if mn_weps=5 then sdol:=400;
  if mn_weps=7 then sdol:=1000;
  if mn_weps=8 then sdol:=2000;
  if mn_weps=9 then sdol:=4000;
  if mn_weps=11 then sdol:=10000;
  if mn_weps=12 then sdol:=2.0000000000E+04;
  if mn_weps=13 then sdol:=4.0000000000E+04;
  if mn_weps=15 then sdol:=1.0000000000E+05;
  if mn_weps=16 then sdol:=2.0000000000E+05;
  if mn_weps=17 then sdol:=4.0000000000E+05;
  if mn_weps=20 then sdol:=1.0000000000E+06;
  str(sdol:1:0,weapon);
  print('You can sell your '+mn_wep+' for $'+weapon);
  prt('Do you wish to do so?'); onek(cj,'YN');
  case cj of
    'Y':begin
          print('Software Sold.');
          mn_mon:=mn_mon+(sdol);
          mn_wep:='Dumb Terminal';
          mn_weps:=1;
        end;
    'N':print('Aborted.');
  end;
end;


procedure wshop;
begin
 cj:='?';
 repeat
   nl;
   if cj='?' then begin
     cls;
     print('LLL Software Shop');
     print('');
     print('Options: ');
     print(' [B] Buy Software      ');
     print(' [S] Sell Software   ');
     print(' [L] List Software');
     print(' [Q] Quit');
   end;
   nl;
   prt('Which (B,L,S,Q,?) : '); onek(cj,'BQLS?');
   case cj of
     'B':bwep;
     'S':swep;
     'L':weplist;
   end;
 until (cj='Q') or hangup;
end;


procedure ashop;
begin
 cj:='?';
 repeat
   nl;
   if cj='?' then begin
     cls;
     print('LLL Backup Shop');
     print('');
     print('Options: ');
     print(' [B] Buy Backup       ');
     print(' [S] Sell Backup  ');
     print(' [L] List Backup');
     print(' [Q] Quit');
   end;
   nl;
   prt('Which (B,L,S,Q,?) : '); onek(cj,'BQLS?');
   case cj of
     'B':barm;
     'S':sarm;
     'L':armlist;
   end;
 until (cj='Q') or hangup;
end;



procedure ldat;
var duser,lasda:astr; fod,fof,foi:integer;
begin
  fod:=0; fof:=0; foi:=0;
  assign(f,gfilespath+'dates.lch');
  {$I-} reset(f); {$I+}
  if ioresult=0 then begin
    repeat
     readln(f,duser);
     readln(f,lasda);
     if eof(f) then fod:=1;
     if duser=mn_name then fod:=1;
    until fod=1;
    if duser=mn_name then fof:=1;
    close(f);
    end;
  if fof=0 then begin
    {$I-} reset(f); {$I+}
    if ioresult<>0 then foi:=1;
    close(f);
    if foi=0 then {$I-} append(f); {$I+}
    if foi=1 then {$I-} rewrite(f); {$I+}
    writeln(f,mn_name);
    writeln(f,date);
    close(f);
    end;
  copt:=gfilespath+'dates.lch';
  copu:=gfilespath+'dates2.lch';
  copit;
  if fof=1 then begin
    if lasda<>date then begin
      close(f);
      assign(g,gfilespath+'dates2.lch');
      {$I-} reset(g); {$I+}
      {$I-} rewrite(f); {$I+}
     repeat
      readln(g,kkk);
      if kkk=mn_name then begin
         writeln(f,mn_name);
         writeln(f,date);
         readln(g,kkl);
         end;
      if kkk<>mn_name then writeln(f,kkk);
     until eof(g);
     close(f);
     close(g);
     mn_runs:=3;
     end;
   end;
end;


procedure rbank;
var hjl:integer; ghj:astr; hjk:real;
begin
  hjl:=0;
  assign(f,gfilespath+'bank.lch');
  {$I-} reset(f); {$I+}
  if ioresult=0 then begin
   readln(f,tot_bank);
   repeat
    readln(f,ghj);
    readln(f,hjk);
    if eof(f) then hjl:=1;
    if ghj=mn_name then hjl:=1;
    mn_bank:=0;
   until hjl=1;
   close(f);
   if ghj=mn_name then begin
       mn_bank:=hjk;
       end;
   if ghj<>mn_name then begin
                          mn_bank:=0;
                          {$I-} append(f); {$I+}
                          writeln(f,mn_name);
                          writeln(f,mn_bank);
                          close(f);
                        end;
   end;
  if hjl=0 then begin
                  mn_bank:=0;
                  tot_bank:=0;
                  {$I-} rewrite(f); {$I+}
                  writeln(f,tot_bank);
                  writeln(f,mn_name);
                  writeln(f,mn_bank);
                  close(f);
                end;
end;



procedure sbank;
begin
  copt:=gfilespath+'bank.lch';
  copu:=gfilespath+'bank2.lch';
  copit;
  assign(f,gfilespath+'bank.lch');
  assign(g,gfilespath+'bank2.lch');
  {$I-} rewrite(f); {$I+}
  {$I-} reset(g); {$I+}
  writeln(f,tot_bank);
  readln(g,kkk);
 repeat
  readln(g,kkk);
  if kkk=mn_name then begin
                        writeln(f,mn_name);
                        writeln(f,mn_bank);
                        readln(g,kkl);
                      end;
  if kkk<>mn_name then writeln(f,kkk);
 until eof(g);
 close(f); close(g);
end;


procedure pbank;
var lbank:real;
begin
  lbank:=mn_bank;
  mn_bank:=mn_bank+mn_mon;
  mn_mon:=0;
  if mn_bank<>lbank then tot_bank:=tot_bank+(mn_bank-lbank);
  str(mn_bank:1:0,bank);
  print('$'+bank+' now in LLL account.');
end;


procedure wbank;
var lasbank:real;
begin
  lasbank:=mn_mon;
  mn_mon:=mn_mon+mn_bank;
  mn_bank:=0;
  if mn_mon<>lasbank then tot_bank:=tot_bank-(mn_mon-lasbank);
  str(mn_mon:1:0,money);
  print('$'+money+' now in possesion.  $0 in LLL account.');
end;



procedure robank2;
var jlk:integer; jll:real;
begin
  randomize;
  jlk:=TRUNC((mn_gl*10)/mn_weps);
  if jlk<2 then jlk:=2;
  jll:=random(jlk);
  if jll=1 then begin
            mn_mon:=mn_mon+tot_bank;
            mn_bank:=0;
            print('You successfully hacked out cards!');
            print('You transferred $'+cstrr(tot_bank,10)+' to your account!');
            tot_bank:=0;
            assign(f,gfilespath+'bank.lch');
            {$I-} rewrite(f); {$I+}
            writeln(f,tot_bank);
            writeln(f,mn_name);
            writeln(f,mn_bank);
            close(f);
            end;
  if jll<>1 then begin
             print('You were caught.  The LLL now requires you to crash more harddrives to make');
             print('another level.');
             mn_gl:=mn_gl+(mn_lev*5);
             end;
end;



procedure robank;
begin
  print('Failing to hack out the credit cards will get the LLL *MAD*.');
  if times >= 3 then
    begin
      Ansic(7);print('Sorry, you can only try to hack the');
      ansic(7);print('cards 3 times.');
    end
  else
    begin
      prt('Still hack? '); onek(cj,'YN');
      case cj of
      'Y':begin
            times:=times+1;
            robank2;
          end;
      'N':print('Aborted.');
      end;
    end;
end;


procedure sspell;
begin
  copt:=gfilespath+'spell.lch';
  copu:=gfilespath+'spell2.lch';
  copit;
  assign(f,gfilespath+'spell.lch');
  assign(g,gfilespath+'spell2.lch');
  {$I-} rewrite(f); {$I+}
  {$I-} reset(g); {$I+}
 repeat
  readln(g,kkk);
  if kkk=mn_name then begin
                        writeln(f,mn_name);
                        if (mn_asp < 0) or (mn_asp > 5) then mn_asp := 5;
                        if (mn_hsp < 0) or (mn_hsp > 5) then mn_hsp := 5;
                        writeln(f,mn_hsp);
                        writeln(f,mn_asp);
                        readln(g,kkl);
                        readln(g,kkl);
                      end;
  if kkk<>mn_name then writeln(f,kkk);
 until eof(g);
 close(f); close(g);
end;


procedure rspell;
var hjl,hok,hoo:integer; ghj:astr;
begin
  hjl:=0;
  assign(f,gfilespath+'spell.lch');
  {$I-} reset(f); {$I+}
  if ioresult=0 then begin
   repeat
    readln(f,ghj);
    readln(f,hok);
    readln(f,hoo);
    if eof(f) then hjl:=1;
    if ghj=mn_name then hjl:=1;
   until hjl=1;
   close(f);
   if ghj=mn_name then begin
                   mn_hsp:=hok;
                   mn_asp:=hoo;
                   if (mn_asp < 0) or (mn_asp > 5) then mn_asp := 5;
                   if (mn_hsp < 0) or (mn_hsp > 5) then mn_hsp := 5;
                   end;
   if ghj<>mn_name then begin
                          mn_hsp:=1;
                          mn_asp:=1;
                          {$I-} append(f); {$I+}
                          writeln(f,mn_name);
                          writeln(f,mn_hsp);
                          writeln(f,mn_asp);
                          close(f);
                         end;
   end;
  if hjl=0 then begin
                  mn_hsp:=1;
                  mn_asp:=1;
                  {$I-} rewrite(f); {$I+}
                  writeln(f,mn_name);
                  writeln(f,mn_hsp);
                  writeln(f,mn_asp);
                  close(f);
                end;
end;
