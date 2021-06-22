program Leech;

{ Version 1.0
{ Program written by ALF Software

{$V-} {$C-}
uses common, wwiv5chn;
{ $I COMMON.PAS }

VAR
   f,g:text;
   ranks,heq,heo,hes,yonum,pm,ph,pk,cstu,pd,pe,pf,pg,ii,pj,pl:integer;
   mn_name,mn_wep,mn_arm:astr;
   nc,gg,mn_num,mn_lev,mn_gl,mn_weps,mn_arms,mn_runs,mn_fl,mn_ufl:integer;
   nus,mn_hp,mn_rank:integer;
   fc,hall,het,hues,yojunk,yoname,yomama,cop,fn_name:astr;
   kkk,kkl,fk,fn_nam,fh,in_name,in_wep,in_arm:astr;
   times,suq,in_weps,in_arms,in_rank,in_num,in_lev,in_gl,fu:integer;
   run,mn_hsp,mn_asp,pn,yolevel,huex:integer;
   cm,cj:char;
   wcf,fn_gl,fn_lev,fn_runs,fn_ufl,fn_num,fn_weps,fn_arms,fg,guf:integer;
   jg,ji,mn_bank,tot_bank,fv,in_mon,fn_mon,hem,hel,mn_mon,fn_hi,mn_hi:real;
   money,bank,gamble,fn_wep,fn_arm,copt,copu:astr;
   gfilespath:astr;



procedure dly;
var dly:integer;
begin
  for dly:=1 to 2 do begin
  end;
  for dly:=1 to 2 do begin
  end;
end;



function lower(s:astr):astr;
var
  spaceflag :boolean;
  i : integer;
begin
  spaceflag := true;
  for i := 1 to length(s) do
    begin
      if s[i] <> #32 then
        begin
          if not spaceflag then
            begin
              if ((s[i] >= 'A') and (s[i] <= 'Z')) then
                s[i] := chr(ord(s[i])+32);
            end
          else
            spaceflag := false;
        end
      else
        spaceflag := true;
    end;
  lower := s;
end;

procedure readat;
begin
  nc:=1;
  pe:=1;
  NUS:=1;
  readln(f,mn_num);
  readln(f,mn_wep);
  readln(f,mn_arm);
  readln(f,mn_weps);
  readln(f,mn_arms);
  readln(f,mn_lev);
  readln(f,mn_gl);
  readln(f,mn_mon);
  readln(f,mn_runs);
  mn_fl:=10;
  mn_ufl:=3;
  mn_hp:=(mn_lev*10);
  mn_hi:=mn_hp;
end;


procedure sast3;
begin
  assign(f,gfilespath+'leechs.dat');
  if pf=1 then {$I-} rewrite(f); {$I+}
  if pf<>1 then {$I-} append(f); {$I+}
  writeln(f,mn_name);
  writeln(f,mn_num);
  writeln(f,mn_wep);
  writeln(f,mn_arm);
  writeln(f,mn_weps);
  writeln(f,mn_arms);
  writeln(f,mn_lev);
  writeln(f,mn_gl);
  writeln(f,mn_mon);
  writeln(f,mn_runs);
  close(f);
end;


procedure chekon;
var ryn:integer;
begin
  ryn:=0;
  NUS:=0;
  pf:=0;
  pl:=0;
  pk:=1;
  times:=0;
  mn_name:=lower(thisuser.name);
  assign(f,gfilespath+'leechs.dat');
  {$I-} reset(f); {$I+}
  if ioresult<>0 then
    begin
      rewrite(f);
      close(f);
      {$I-} reset(f); {$I+}
      pf:=1;
    end
  else
    begin
      pf:=0;
      repeat
        readln(f,yoname);
        if yoname=mn_name then
          readat
        else
          begin
            pl:=pl+1;
            if pl=10 then
              begin
                pl:=0;
                pk:=pk+1;
              end;
          end;
      until eof(f);
    end;
 close(f);
 if pe<>1 then begin
                 ansic(3);
                 print('Hello, new leech!');
                 ansic(1);
                 pausescr;
                 cls;
                 mn_wep:='Dumb Terminal';
                 mn_arm:='None';
                 mn_weps:=1;
                 mn_arms:=1;
                 mn_lev:=1;
                 mn_gl:=10;
                 mn_mon:=10;
                 mn_runs:=3;
                 mn_fl:=10;
                 mn_ufl:=3;
                 mn_hi:=10;
                 mn_hp:=10;
                 if pf=1 then
                   begin
                     mn_num:=1;
                   end;
                 if pf <> 1 then
                   begin
                     if pk <= 1 then
                       begin
                         mn_num:=1;
                       end
                     else
                       begin
                        mn_num:=pk;
                       end;
                   end;
                 sast3;
               end;
end;


procedure copit;
begin
  assign(f,copt);
  assign(g,copu);
  {$I-} reset(f); {$I+}
  {$I-} rewrite(g); {$I+}
  while not eof(f) do begin;
                        readln(f,cop);
                        writeln(g,cop);
                      end;
  close(f); close(g);
end;


procedure detrank;
var py:integer;
begin
  pj:=0;
  py:=1;
  pg:=29;
  cls;
  assign (f,gfilespath+'leechs.DAT');
  {$I-} reset(f); {$I+}
  for ii:=1 to 30 do begin
         repeat
          readln(f,yojunk);
          readln(f,yonum);
          readln(f,yomama);
          readln(f,yomama);
          readln(f,yomama);
          readln(f,yomama);
          readln(f,yolevel);
          readln(f,yomama);
          readln(f,yomama);
          readln(f,yomama);
          if (ii+pg)=yolevel then begin
            pj:=pj+1;
            if yonum=mn_num then ranks:=py;
           end;
         until eof(f);
         py:=pj+1;
         reset(f);
         pg:=pg-2;
         end;
  close(f);
end;


procedure sast2;
begin
  pd:=1;
  writeln(g,mn_name);
  writeln(g,mn_num);
  writeln(g,mn_wep);
  writeln(g,mn_arm);
  writeln(g,mn_weps);
  writeln(g,mn_arms);
  writeln(g,mn_lev);
  writeln(g,mn_gl);
  writeln(g,mn_mon);
  writeln(g,mn_runs);
  readln(f,yoname);
  readln(f,yoname);
  readln(f,yoname);
  readln(f,yoname);
  readln(f,yoname);
  readln(f,yoname);
  readln(f,yoname);
  readln(f,yoname);
  readln(f,yoname);
end;



procedure sast;
begin
  pd:=0;
  copt:=gfilespath+'leechs.dat';
  copu:=gfilespath+'leechs2.dat';
  copit;
  assign(g,gfilespath+'leechs.dat');
  assign(f,gfilespath+'leechs2.dat');
  {$I-} rewrite(g); {$I+}
  {$I-} reset(f); {$I+}
  while not eof(f) do begin
                        readln(f,yoname);
                        if yoname=mn_name then sast2;
                        if pd=0 then writeln(g,yoname);
                        if pd=1 then pd:=0;
                      end;
  close(f); close(g);
end;


{$I leechp2.inc}


procedure return1;
begin
  sast;
  sbank;
  sspell;
  ansic(7);nl;
  print('Now returning to an environment with even WORSE users...');nl;
  pe:=0; pf:=0; pd:=0; pg:=0; ph:=0; pk:=0; pj:=0; pl:=0; pm:=0; pn:=0; nc:=0;
  {return;}
end;


procedure return2;
begin
  ansic(6);nl;
  print('Game has been rerolled!');nl;
  ansic(7);nl;
  print('Now returning to an environment with even WORSE users...');
  pe:=0; pf:=0; pd:=0; pg:=0; ph:=0; pk:=0; pj:=0; pl:=0; pm:=0; pn:=0; nc:=0;
  { return; }
end;


{$I leechp1.inc}


procedure cruns;
begin
  ldat;
  if (mn_runs=0) and (thisuser.sl < 255) then begin
     if nus=0 then mn_runs:=3
              else begin
                      print('Hey, you ARE a leech!  Only 3 times per day!');
                      return1;
              end;
  end;
  if mn_runs>0 then mn_runs:=mn_runs-1;
   if nc=1 then begin
              cls;
              ansic(3);
              print('Glad to see you back, '+mn_name+'!');
              ansic(1);
              pausescr;
              end;
end;



procedure format;
begin
  prt('Format Harddrive -- will erase all stats.  Sure? '); onek(cm,'YN');
  case cm of
    'Y':begin
                MN_LEV:=1;
                MN_GL:=10;
                MN_MON:=10;
                MN_ASP:=1;
                MN_HSP:=1;
                mn_weps:=1;
                mn_arms:=1;
                mn_wep:='Dumb-Terminal';
                mn_arm:='None';
                mn_fl:=10;
                mn_ufl:=3;
                MN_NAME:=LOWER(THISUSER.NAME);
                mn_bank:=0;
                print('');
                ansic(6);
                print('Harddrive formatted!');
                return1;
               END;
    'N':print('Aborted.');
  end;
end;


procedure prst;
begin
  cls;
  mn_rank:=ranks;
  ansic(4); print('Leech:  '+mn_name); ansic (1);
  print('Leech #'+cstr(mn_num));
  print('Level  '+cstr(mn_lev));
  print('Rank:                   '+cstr(mn_rank));
  print('Software:               '+mn_wep);
  print('Backup:                 '+mn_arm);
  print('Drives left to crash:   '+cstr(mn_gl));
  str(mn_mon:1:0,money);
  print('Money:                 $'+money);
  str(mn_bank:1:0,bank);
  print('Money in LLL account:  $'+bank);
  print('Games left today:       '+cstr(mn_runs));
  print('Fast Backups Left:      '+cstr(mn_hsp));
  print('Trojan Horses left:     '+cstr(mn_asp));
  print('Calls to BBS''s left:    '+cstr(mn_fl));
  print('Calls to leeches left:  '+cstr(mn_ufl));
  print('Megs left:              '+cstr(trunc(mn_hi))+'('+cstr(mn_hp)+')');
end;



procedure mnu;
begin
  cls;
  if okansi then printfile(gfilespath+'ibmmenu.lch') else printfile(gfilespath+'aplmenu.lch');
end;



procedure lll;
begin
  cls;
  print('Dialing LLL....');
  dly;
  print('CONNECT');
  cm:='?';
 repeat
  nl;
  print('Welcome to the Lame Local Leeches BBS!');
  nl;
  prt('Command (? for Help)'); onek(cm,'DQHCLEGBS?F');
  case cm of
    'H':ashop;
    'D':printfile(gfilespath+'hallfame.lch');
    'C':robank;
    'L':maxlist;
    'E':exmax;
    'G':gamb;
    'B':bulle;
    'S':wshop;
    '?':printfile(gfilespath+'lllmenu.lch');
    end;
 until (cm='Q') or hangup;
 print('NO CARRIER');
end;


procedure lchmenu;
var cb:astr;
begin
 suq:=0;
 repeat
  if mn_lev>30 then fbat;
  print('');tleft;checkhangup;if hangup then return1;
  if okansi then prt('C>') else prt(']');
  input(cb,8);
   if cb='?' then mnu;
   if cb='DIR' then mnu;
   if cb='CATALOG' then MNU;
   if cb='HELP' then printfile(gfilespath+'instruct.lch');
   if cb='LLL' then LLL;
   if cb='CALL' then begin
         if mn_fl<1 then print('Overuse error.') else CALL;
         end;
   if cb='HACK' then begin
         if mn_ufl<1 then print('Overuse error.') else HACK;
         end;
   if cb='FORMAT' then format;
   if cb='STATUS' then prst;
   if cb='CREDITS' then printfile(gfilespath+'CREDITS.LCH');
   if cb='+' then pbank;
   if cb='-' then wbank;
   IF cb='UE' then doctor;
   if cb='QUIT' then suq:=1;
 until (suq=1) or hangup;
end;


begin
  chain_init;
  gfilespath := 'gfiles\';
  iport;
  cls;
  printfile(gfilespath+'opening.lch');
  pausescr;
  cls;
  topscr;
  chekon;
  cruns;
  rbank;
  rspell;
  copit;
  lbulle;
  CLS;
  print('Booting up...');
  detrank;
  nl;
  lchmenu;
  return1;
end.