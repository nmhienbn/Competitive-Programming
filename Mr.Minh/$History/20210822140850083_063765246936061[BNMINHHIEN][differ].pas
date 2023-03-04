const   fi      ='differ.inp';
        fo      ='differ.out';
        maxn    =round(1e5+5);
        lim     =round(1e9);
var     f,g     :text;
        s       :ansistring;
        xd,dem  :array['a'..'z'] of longint;
        n,kq    :longint;

function        max(i,j :longint):longint;
begin
        if i>j then exit(i) else exit(j);
end;

procedure       nhap;
begin
        assign(f,fi);   reset(f);
        readln(f,n);
        readln(f,s);
        close(f);
end;

procedure       xuli;
var     j,t,x     :char;
        i,chenh   :longint;
        ok        :boolean;
begin
        kq:=0;
        for i:=1 to n do xd[s[i]]:=1;
        for x:='a' to 'z' do if xd[x]=1 then
                begin
                        chenh:=0; ok:=false;
                        for t:='a' to 'z' do dem[t]:=0;
                        for i:=1 to n do
                        begin
                                if s[i]=x then
                                   begin
                                   for t:='a' to 'z' do dec(dem[t]);
                                   ok:=true;
                                   end
                                else
                                if dem[s[i]]<0 then
                                      begin
                                                ok:=false;
                                                dem[s[i]]:=1;
                                      end else inc(dem[s[i]]);
                         if ok then chenh:=max(chenh,dem[s[i]]) else
                                    chenh:=max(chenh,dem[s[i]]-1);
                         end;
                         kq:=max(kq,chenh);
                end;
end;

procedure       inkq;
begin
        assign(g,fo);   rewrite(g);
        write(g,kq);
        close(g);
end;

BEGIN
        nhap;
        xuli;
        inkq;
END.
