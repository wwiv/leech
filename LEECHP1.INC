function mln(i:astr; l:integer):astr;
begin
  while length(i)<l do i:=i+' ';
  mln:=i;
end;

procedure maxlist;
var
li:astr; px:integer;
abort,next:boolean;

begin
  pj:=0;
  px:=1;
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
            li:=mln(mln(mln('Rank: '+cstr(px),12)+'Level '+
            cstr(yolevel),25)+'Leech #'+cstr(yonum),42)+'Name:  '+yojunk;
            printacr(li,abort,next)
            end;
         until eof(f) or hangup;
         px:=pj+1;
         reset(f);
         pg:=pg-2;
         end;
  close(f);
end;


procedure exmax;
begin
  cstu:=(mn_lev)*10;
  if mn_mon>=cstu then begin
    cls;
    maxlist;
    print('');
    ph:=1;
   repeat
    repeat
     prt('Enter number of the leech to examine:  '); input(hues,3);
     huex:=value(hues);
    until (huex>=0) or hangup;
   until (huex<=pj) or hangup;
   if huex>=1 then begin
    prt('Are you aware of the fact that it''ll cost you $'+cstr(cstu)+'  [Y/N] '); onek(cm,'YN');
    if cm='Y' then begin
            assign(f,gfilespath+'leechs.dat');
            {$I-} reset(f); {$I+}
           for ii:=1 to huex do begin
            readln(f,in_name);
            readln(f,in_num);
            readln(f,in_wep);
            readln(f,in_arm);
            readln(f,yomama);
            readln(f,yomama);
            readln(f,in_lev);
            readln(f,in_gl);
            readln(f,in_mon);
            readln(f,yomama);
           end;
              cls;
              print('Searching....');
              nl;
              detrank;
              in_rank:=ranks;
              ansic(3); print('Leech:  '+in_name); ansic(0);
              print('Leech #'+cstr(in_num));
              print('Level  '+cstr(in_lev));
              print('Rank:                '+cstr(in_rank));
              print('Software:            '+in_wep);
              print('Backup:              '+in_arm);
              str(in_mon:1:0,money);
              print('Money:              $'+money);
              print('Megs left:           '+cstr(in_lev*10)+'('+cstr(in_lev*10)+')');
              mn_mon:=mn_mon-cstu;
           close(f);
      if cm='N' then print('Then why did you do this command, stupid?');
      end;
     end;
     IF huex<1 THEN PRINT('Aborted.');
    end;
    if ph<>1 then print('You can''t afford to do that!');
end;



procedure healw(hes:real);
begin
  if mn_mon>=hel then begin
    mn_mon:=(mn_mon-hel);
    mn_hi:=(mn_hi+hes);
    print('We recover '+cstr(trunc(hes))+' megs.');
    pm:=1;
    end;
  if pm=0 then print('Get out!  You don''t have enough money!');
end;



procedure doctor;
begin
 pm:=0;
 cls;
  hem:=(mn_hp-mn_hi);
  heo:=(mn_lev*4);
  print('You have '+cstr(trunc(hem))+' deleted megs.');
  print('It will cost $'+cstr(heo)+' to recover each meg.');
  print('');
  prt('Unerase [A]ll or [S]ome megs? '); onek(cm,'AS');
  case cm of
    'A':begin
          hel:=(hem*heo);
          healw(hem);
        end;
    'S':begin
          print('');
         repeat
          prt('How many megs to unerase?  '); input(het,3);
          heq:=value(het);
          if heq<0 then heq:=0;
         until (heq<=hem) or hangup;
          hel:=(heq*heo);
          healw(heq);
        end;
  end;
end;


procedure gamb;
var gam:real; gal:astr; iz:real;
begin
  cls;
  nl;
  str(mn_mon:1:0,money);
  print('You have $'+money);
  print('');
 repeat
  prt('How much do you want to gamble?  '); input(gal,6);
  gam:=value(gal);
  if gam<0 then gam:=0;
 until (gam<=mn_mon) or hangup;
 if gam>0 then begin
{  randomize; }
  iz:=random(50);
  if iz<11 then begin
                 str(gam:1:0,gamble);
                 print('You won $'+gamble+'!!');
                 mn_mon:=(mn_mon+gam);
               end;
  if iz>10 then begin
                  print('Thank you.  Now I''ll take back my MARKED CARDS!');
                  mn_mon:=(mn_mon-gam);
                end;
 end;
end;



procedure hspell;
var jx,ji:real;
begin
  randomize;
  jx:=random(5);
  ji:=(jx*mn_weps);
  ansic(6);
  print('Your hard disk has a File Allocation Table error!');
  print('Say goodbye to '+cstrr(ji,10)+' megs!');
  ansic(1);
  mn_hi:=mn_hi-ji;
end;


procedure fight2;
var hta,htb,htc:real; hthm,htyu:real;
begin
  hta:=random(10);
  htb:=random(10);
  htc:=random(20);
  hthm:=trunc((mn_weps*hta)/fn_arms);
  htyu:=trunc((fn_weps*htb)/mn_arms);
  ansic(3);
  if hthm>=1 then print('You trash '+cstr(trunc(hthm))+' megs!') else print('You got line noise!');
  fn_hi:=fn_hi-hthm;
  ansic(7);
  if fn_hi>0 then begin
                   if htyu>=1 then print('They purge '+cstr(trunc(htyu))+' megs!') else
                          print('They deleted an EMPTY directory!');
                   mn_hi:=mn_hi-htyu;
                    if htc=6 then hspell;
                   end;
end;


procedure sast5;
begin
  pd:=1;
  writeln(g,fn_nam);
  writeln(g,fn_num);
  writeln(g,fn_wep);
  writeln(g,fn_arm);
  writeln(g,fn_weps);
  writeln(g,fn_arms);
  writeln(g,fn_lev);
  writeln(g,fn_gl);
  writeln(g,fn_mon);
  writeln(g,fn_runs);
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


procedure sast4;
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
                        if yoname=fn_nam then sast5;
                        if pd=0 then writeln(g,yoname);
                        if pd=1 then pd:=0;
                      end;
  close(f); close(g);
end;



procedure upda;
begin
  fn_mon:=fn_mon+mn_mon;
  mn_mon:=0;
  fn_gl:=fn_gl-(mn_lev*3);
  if fn_gl<=0 then begin
                     fn_lev:=fn_lev+1;
                     fn_gl:=fn_lev*10;
                   end;
  if fn_weps<mn_weps then begin
                            print('');
                            print('He downloaded your software!');
                            in_weps:=fn_weps;
                            in_wep:=fn_wep;
                            fn_weps:=mn_weps;
                            fn_wep:=mn_wep;
                            mn_weps:=in_weps;
                            mn_wep:=in_wep;
                          end;
  if fn_arms<mn_arms then begin
                            print('');
                            print('He stole your backup!');
                            in_arms:=fn_arms;
                            in_arm:=fn_arm;
                            fn_arms:=mn_arms;
                            fn_arm:=mn_arm;
                            mn_arms:=in_arms;
                            mn_arm:=in_arm;
                          end;
  sast4;
end;



procedure yudead;
begin
  print('');
  print('There goes your hard disk!');
  if guf=0 then mn_mon:=mn_mon/2;
  if guf=1 then upda;
  if mn_lev=31 then begin
                      mn_lev:=30;
                      mn_gl:=300;
                    end;
  return1;
end;


procedure mlev;
begin
  mn_lev:=mn_lev+1;
  print('');
  print('The LLL is pleased with this performance.  You are now level '+cstr(mn_lev));
  mn_hi:=mn_hi+10;
  mn_hp:=mn_hp+10;
  mn_gl:=10*mn_lev;
  mn_asp:=mn_asp+1;
  if mn_asp < 0 then mn_asp := 0;
  if mn_asp > 30 then mn_asp := 30;
  mn_hsp:=mn_hsp+1;
  if mn_hsp < 0 then mn_hsp := 0;
  if mn_hsp > 30 then mn_hsp := 30;
end;


procedure upda2;
begin
  fn_mon:=0;
  print('');
 if mn_lev>=fn_lev then begin
  mn_gl:=mn_gl-(fn_lev*3);
  if mn_gl>0 then print('The LLL is proud and will give you credit for this.');
  if mn_gl<=0 then print('The LLL couldn''t be more proud!  They promote you a level!');
  end;
 if mn_lev<fn_lev then begin
  in_lev:=mn_lev;
  in_gl:=mn_gl;
  mn_lev:=fn_lev;
  mn_gl:=fn_gl;
  fn_gl:=in_gl;
  fn_lev:=in_lev;
  print('The LLL promotes you to level '+cstr(mn_lev)+'!');
  print('They demote him to level '+cstr(fn_lev)+'!');
  end;
  if fn_weps>mn_weps then begin
                            print('');
                            print('You downloaded his software!');
                            in_weps:=fn_weps;
                            in_wep:=fn_wep;
                            fn_weps:=mn_weps;
                            fn_wep:=mn_wep;
                            mn_weps:=in_weps;
                            mn_wep:=in_wep;
                          end;
  if fn_arms>mn_arms then begin
                            print('');
                            print('You stole his backup!');
                            in_arms:=fn_arms;
                            in_arm:=fn_arm;
                            fn_arms:=mn_arms;
                            fn_arm:=mn_arm;
                            mn_arms:=in_arms;
                            mn_arm:=in_arm;
                          end;
  sast4;
end;



procedure theydead;
begin
  print('');
  print('Their computer is FRIED!');
  print('');
  print('And look, here''s his credit card # with $'+cstr(trunc(fn_mon))+' in the account!');nl;
  mn_mon:=mn_mon+fn_mon;
  if guf=0 then mn_gl:=mn_gl-fg;
  if guf=1 then upda2;
  if mn_gl<=0 then mlev;
  sast;
  detrank;
end;


procedure ospell;
begin
          if mn_asp=0 then print('OOOOPS!  You accidentally erased it!');
          if mn_asp>0 then begin
                             randomize;
                             mn_asp:=mn_asp-1;
                             jg:=random(5);
                             ji:=(jg*mn_weps);
                             ansic(6);
                             print('You upload a trojan horse...');
                             dly;
                             ansic(1);
                             print('The idiot runs it!  '+cstrr(ji,10)+' megs are trashed!');
                             fn_hi:=fn_hi-ji;
                           end;
end;


procedure dspell;
begin
          if mn_hsp=0 then print('The files were completely purged!');
          if mn_hsp>0 then begin
                             randomize;
                             mn_hsp:=mn_hsp-1;
                             jg:=random(5);
                             ji:=(jg*mn_arms);
                             ansic(6);
                             print('You run a backup program...');
                             dly;
                             ansic(1);
                             if (mn_hi+ji)>mn_hp then
                                print('You recover all of megs back!')
                                 else
                                  print('You recover '+cstrr(ji,10)+' megs back!');
                             mn_hi:=mn_hi+ji;
                             if mn_hi>mn_hp then mn_hi:=mn_hp;
                           end;
end;



procedure fight;
var rune:integer;
begin
  nl; nl;
  run:=0;
  rune:=0;
  print('You begin to hack!');
 repeat
  nl; nl;
  print('You have '+cstr(trunc(mn_hi))+' megs left.');
  print('They have '+cstr(trunc(fn_hi))+' megs left.');
  print('');
  prt('[T]rash Files, [D]rop Carrier, [U]pload Trojan Horse, or [B]ackup Files:  '); onek(cm,'TDUB');
  case cm of
    'T':fight2;
    'D':run:=1;
    'B':dspell;
    'U':ospell;
  end;
  if fn_hi<=0 then rune:=1;
  if mn_hi<=0 then rune:=1;
  if run=1 then rune:=1;
 until (rune=1) or hangup;
 if mn_hi<=0 then yudead;
 if fn_hi<=0 then theydead;
 if run=1 then print('NO CARRIER');
end;



procedure call;
begin
  randomize;
  guf:=0;
  cls;
  print('Welcome to '+mn_wep+'!');
  nl;
  repeat
   prt('Which BBS to call (? for list) '); input(fh,2);
   fg:=value(fh);
   if fh='?' then begin
      printfile(gfilespath+'bbs.lch');
      fg:=-1;
      end;
  until (fg>=0) or hangup;
 if fg>=1 then begin
  print('Dialing...');
  dly;
  print('CONNECT');
  mn_fl:=mn_fl-1;
  fn_hi:=(fg*7);
  fn_mon:=(fg*60);
  fn_weps:=fg;
  fn_arms:=1;
  fight;
  end;
 if fg<1 then print('Aborted.');
end;


procedure hack;
var gi,fp,fq:integer;
begin
  gi:=0; fp:=0; fq:=0;
  randomize;
  guf:=1;
  maxlist;
 repeat
  repeat
   repeat
    prt('Enter Leech # of computer to hack:  '); input(fk,3);
    wcf:=value(fk);
   until (wcf<>mn_num) or hangup;
  until (wcf<=pj) or hangup;
   print('Searching for Leech #...');
   dly;
   wcf:=value(fk);
   if wcf<1 then gi:=1;
   assign(f,gfilespath+'leechs.dat');
   {$I-} reset(f); {$I+}
    repeat
     readln(f,fn_nam);
     readln(f,fn_num);
     readln(f,fn_wep);
     readln(f,fn_arm);
     readln(f,fn_weps);
     readln(f,fn_arms);
     readln(f,fn_lev);
     readln(f,fn_gl);
     readln(f,fn_mon);
     readln(f,fn_runs);
     if fn_num=wcf then begin
                          fp:=1;
                          fq:=1;
                        end;
     if gi=1 then begin
                    fp:=1;
                    fq:=1;
                  end;
     if eof(f) then fp:=1;
    until fp=1;
 until (fq=1) or hangup;
 close(f);
 if gi=0 then begin
                print('Found!');
                mn_ufl:=mn_ufl-1;
                fn_hi:=fn_lev*10;
                fight;
              end;
 if gi=1 then print('Not found--aborted.');
end;


procedure fbat;
begin
  cls;
  print('Congratulations, '+mn_name+'!');
  print('You have become a level 31 leech!  Now time for the BIG challenge.');
  print('You have to crash the LLL computer!  Yes, you have all of your megs back,');
  print('but you''ll need them against the LLL.  If you fail, the LLL will be mad');
  print('and demote you to level 30.  Good luck!');
  pausescr;
  fn_hi:=360;
  mn_hi:=310;
  fn_weps:=mn_weps;
  fn_arms:=mn_arms;
  fight;
  if run=1 then begin
          print('The LLL is pissed.  Go back and repeat level 30!');
          mn_lev:=30;
          mn_gl:=300;
          end;
  if run=0 then begin
          print('The LLL''s computer is done for!  They enter you into the leech hall of fame!');
          assign(f,gfilespath+'hallfame.lch');
          {$I-} append(f); {$I+}
          if ioresult<>0 then rewrite(f);
          writeln(f,mn_name);
          close(f);
          assign (f,gfilespath+'leechs.dat');
          {$I-} erase(f); {$I+}
          assign (f,gfilespath+'leechs2.dat');
          {$I-} erase(f); {$I+}
          assign (f,gfilespath+'bank.lch');
          {$I-} erase(f); {$I+}
          assign (f,gfilespath+'bank2.lch');
          {$I-} erase(f); {$I+}
          assign (f,gfilespath+'spell.lch');
          {$I-} erase(f); {$I+}
          assign (f,gfilespath+'spell2.lch');
          {$I-} erase(f); {$I+}
          pausescr;
          return2;
          end;
end;
