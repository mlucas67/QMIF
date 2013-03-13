$ifndef dirs_h
    $define dirs_h 1
    
    $include constants.h
    
    public north$, south$, east$, west$
    public northeast$, northwest$, southeast$, southwest$
    public up$, down$, inside$, outside$
    
    get n$(); return north$; end;
    set n$(obj); north$ = obj; end;
    
    get s$(); return south$; end;
    set s$(obj); south$ = obj; end;
    
    get e$(); return east$; end;
    set e$(obj); east$ = obj; end;
    
    get w$(); return west$; end;
    set w$(obj); west$ = obj; end;
    
    get ne$(); return northeast$; end;
    set ne$(obj); northeast$ = obj; end;
    
    get nw$(); return northwest$; end;
    set nw$(obj); northwest$ = obj; end;
    
    get se$(); return southeast$; end;
    set se$(obj); southeast$ = obj; end;
    
    get sw$(); return southwest$; end;
    set sw$(obj); southwest$ = obj; end;
    
    get u$(); return up$; end;
    set u$(obj); up$ = obj; end;
    
    get d$(); return down$; end;
    set d$(obj); down$ = obj; end;
    
    get in$(); return inside$; end;
    set in$(obj); inside$ = obj; end;
    
    get out$(); return outside$; end;
    set out$(obj); outside$ = obj; end;
    
    public sub initdirs()
        north$ = nothing
        south$ = nothing
        east$ = nothing
        west$ = nothing
        northeast$ = nothing
        northwest$ = nothing
        southeast$ = nothing
        southwest$ = nothing
        up$ = nothing
        down$ = nothing
        inside$ = nothing
        outside$ = nothing
    end
    
    public sub showExits()
        crt "Obvious Exits: " :
        first = true
        for each dir in "north$ısouth$ıeast$ıwest$ınortheast$ınorthwest$ısoutheast$ısouthwest$ıup$ıdown$ıinside$ıoutside$"
            roomExit = me->(dir)
            if (roomExit->isNothing()) else
                if (first) then 
                    crt dir['$', 1, 1] : 
                    first = false
                end else 
                    crt ", " : dir['$', 1, 1] :
                end
            end
        next dir
        crt "."
    end
    
    public function go(dir)
        mydir = dir['$', 1, 1] : '$'
        if (me->(mydir)->isNothing()) then 
            crt "You can't go that way."
            return me
        end
        if (me->(mydir)->type() = TYPE_DOOR) then
            if (me->(mydir)->isOpen()) then return me->(mydir)->(mydir)
            crt "You bump your nose on the closed door."
            return me
        end
        if (me->(mydir)->type() = TYPE_ROOM) then return me->(mydir)
        crt "I would try that again if I were you."
        return me
    end
    
$endif
