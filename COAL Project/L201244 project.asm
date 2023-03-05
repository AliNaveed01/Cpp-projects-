;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;COAL PROJECT;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;ANGRY BIRDS;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;NAVEED ALI;;;;;;;;;;;;;;;;;MOIZ SIDDIQUI;;;;;;;;;;;;;;;;;LAIBA MUSHTAQ;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;20L-1244;;;;;;;;;;;;;;;;;;20L-1296;;;;;;;;;;;;;;;;;;;;;;;20L-1374;;;;;;;;;;;;;;;;;;;;;;


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;BSDS -3B ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


[org 0x0100]
jmp start
words:db 'Score : ' ;hardcode score word 
over:db ' ;;;;;GAME OVER ;;;;; ' ;hardcode score word 
leng :dw 23; length of word game over
len:dw 8 ; length of "score : "
scr: dw 0 ; var for prinitng of score.

;col: dw 0x6020


;;;;;;;;;;;;;;;;;;;;;;; subroutine to clear the screen;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


backgnd: 
	push es
	push ax ;pushing ax into stack
	push di ;for saving values of registers
	mov ax, 0xb800 ;;pointing towards the video memory
	mov es, ax ;point es to video base
	mov di, 0 ;point di to top left column

nextl:  mov word [es:di], 0x3020 ;20=code for space(blue)
		add di, 2 ;move to next screen location
		cmp di, 4000 ;has the whole screen cleared
		jne nextl ;if no,then jump on next position.
  pop di ;for restoring values of registers.
  pop ax
  pop es
  ret

;;;;;;;;;;;;;;;;;;;;;;;; code for printing of the grass;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

grass:
	push es
	push ax ;storing val in stack.
	push di
	mov ax, 0xb800 ;pointing to the video memory	
	mov es, ax ;point es to video base
	mov di, 4000 ;moving di to the bottom right corner

lo1:
	mov word [es:di], 0x2020 ;print space on the bottom right location. (in green).
	sub di,2 ; backword greencolor printing 
	cmp di,3358 ;draw green color until 3358
	jne lo1 ;if no, go to lo1.

  pop di ;restoring back.
  pop ax
  pop es
  ret 

;;;;;;;;;;;;;;;;;;;;;;;;code for increasing and displaying the code (6.4);;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

printnum: push bp 
		mov bp, sp 
		push es 
		push ax 
		push bx 
		push cx 
		push dx 
		push di 
		mov ax, 0xb800 
		mov es, ax ; point es to video base 
		mov ax, [bp+4] ; load number in ax 
		mov bx, 10 ; use base 10 for division 
		mov cx, 0 ; initialize count of digits 
nextdigit: mov dx, 0 ; zero upper half of dividend 
		div bx ; divide by 10 
		add dl, 0x30 ; convert digit into ascii value 
		push dx ; save ascii value on stack 
		inc cx ; increment count of values 
		cmp ax, 0 ; is the quotient zero 
		jnz nextdigit ; if no divide it again 
		mov di, 300
		nextpos: pop dx ; remove a digit from the stack 
		mov dh, 0x07 ; use normal attribute 
		mov [es:di], dx ; print char on screen 
		add di, 2 ; move to next screen location 
		loop nextpos ; repeat for all digits on stack
		pop di 
		pop dx 
		pop cx 
		pop bx 
		pop ax 
		pop es 
		pop bp 
		ret 2 

;;;;;;;;;;;;;;;;;;;;;;;;;;code for printing of the tree ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

treee: 
	push es ;pushing reg in stack.
	push ax
	push di	
	push cx
	push dx

	mov ax, 0xb800 ;vid memory
	mov es, ax 
	mov dx,0 ;incrementer for no of trees.
	mov di, 3570 ;the point where we will start printing the trees.

tre: inc dx ;increment it first.
	 cmp dx,4 
     je end

	mov cx,2 ;stem size  = 2 cells
lo2: mov word [es:di], 0x6020 ;stem of trees are made here(represting the brown color).at dith location.
	sub di,160 ;going up in to color the stem.
	loop lo2 ;repeat until cx = 0.

	mov word [es:di], 0x2A2A ;printing branches of trees in diff cordinates.
	sub di,162 

	mov word [es:di], 0x2A2A
	sub di,158

	mov word [es:di], 0x2A2A
	add di,162

	mov word [es:di], 0x2A2A
	add di,158


	add di,180 ;going 20 spaces ahead for printing the next tree.
	jmp tre

end: pop dx ;retrieving values from reg.
	 pop cx	
	 pop di
     pop ax
	 pop es
     ret 

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;subroutine for the printing of bow;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; 

boww: push es ;stack work
	push ax
	push di
	push cx
	push si

	mov ax, 0xb800 ;again poiting to the vid memory.
	mov es, ax ;vid base pointing
	mov di, 3220 ;  

	mov cx,3 ;making stem of the bow
lo3: mov word [es:di], 0x0720 ;dith location (blakc printing.)
	 sub di,160 ;going above.
     loop lo3 ;repeat until cx=0; len  =  3.

	mov si,di ;storing  di somewhere and then changing di to make bow.
	sub di,2 ;left part of V shaped bow.
	mov word [es:di], 0x0720
	sub di,162 
	mov word [es:di], 0x0720

	mov di,si
	add di,2 ;right part of V shaped bow.
	mov word [es:di], 0x0720
	sub di,158
	mov word [es:di], 0x0720


	pop si
	pop cx
	pop di
	pop ax
	pop es
	ret 

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;subroutine for printing of the angry bird ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; here comes our ANGRY BIRD  huiuihuiuhi;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

bird: push es 
	push ax
	push di

	mov ax, 0xb800 ;vid mem
	mov es, ax

			;;;;;;;;;;;;;;Making our bird "ANGRY" by giving red color.

	mov word [es:di], 0x4020 ;printing in red at dith location.	
	add di,2 ;right.
	mov word [es:di], 0x4020
	add di,2 ;right
	mov word [es:di], 0x4020
	sub di,162 ;above.
	mov word [es:di], 0xCC2A ;eyes and peek of angry bird.
	add di,2
	mov word [es:di], 0x34FE


  pop di
  pop ax
  pop es
  ret 

sleep: push cx
	   mov cx, 0xFFFF ;to slow the flow of process.
delay: loop delay
	   pop cx

	   ret 

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;subroutine for the clouds ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

sky:
	push bp ;pushing into the stack.
	mov bp,sp 
	push ax
	push bx
	push cx
	push dx
	push es
	push di

	mov ax,0xb800
	mov es,ax

	mov ax,[bp+6] ;x pos (position of row)
	mov bx,80
	mul bx ;bx*ax    for cordinates. 
	add ax,[bp+4] ;y pos (position of column)
	shl ax,1 ;*2 ;byte offset  
	mov di,ax ;di*ax    passing ax to di so that di can directly access the position. 
	mov ax,0xFF20 ;color of clouds  (colorcode).
	mov cx,7 ;length of sky.
	cld ;  mov the col cx times. (forward printing).
	rep stosw ; printing of that grey clouds.

	sub di,160 ; shifting row upwards 1
	sub di,4 ; subratcing 2 bytes for the printing of cloud in equal directions.
	mov ax,0xFF20 ; color of sky.
	mov cx,5
	std ; backward printing.
	rep stosw ;second stage of clouds.

	sub di,160
	add di,4
	mov ax,0xFF20
	mov cx,3
	cld 
	rep stosw

	sub di,160
	sub di,4
	mov ax,0xFF20
	mov cx,1
	std 
	rep stosw

	pop di
	pop es
	pop dx
	pop cx
	pop bx
	pop ax
	pop bp
	ret 4
	horizontalline:
	push bp             ;pusing base pionter
	mov bp,sp           ;bp ,sp
	push es             ;general reister pushing
	push cx
	push di
	push ax
	push si
	mov ax,0xb800       ; moving vedio memory into ax
 	mov es ,ax          ; es,ax 
	mov al,80           ; calculating location
	mul byte[bp+8]      ; y*80
	add ax,[bp+6]       ; y*80 + x
	shl ax,1            ;(y*80+x)*2
	mov di,ax
	mov ah,[bp+4]       ; ah,colour
	mov cx,[bp+10]      ;counter for no of spaces
lop1:
	mov al,[bp+12]      ; spaces printing
	mov [es:di],ax
	add di,2            ; next position of column
	loop lop1
	
	pop si
	pop ax
	pop di
	pop cx
	pop es
	pop bp
	ret 10
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;CODE for printing of the score;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

Score_printing:

	push bp
	mov bp,sp
	push ax
	push bx
	push cx
	push dx
	push es
	push di 
	push si

	mov ax,0xb800 ;video mem
	mov es,ax

	mov ax,1 ;x pos
	mov bx,80
	mul bx ;
	add ax,60 ;y pos
	shl ax,1 ;hardcode x and y pos... cuz we dont need to change its pos bar bar. 
	mov di,ax ;

	mov si,words ;score word.
	mov cx,[len] ; length of score
	mov ah,0x07 ; color of score.
	cld ; moving ahead.
nextchar:
	lodsb ;load the str into mem  (s) ready to be printed.
	stosw ; printing the s word on the vid mem.
	loop nextchar ; lentgh of our score word.

	pop si
	pop di
	pop es
	pop dx
	pop cx
	pop bx
	pop ax
	pop bp
	ret 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;code for writing game over in the middle of the string;;;;;;;;;;;;;;;;;;;;;;;

gameover:

	push bp
	mov bp,sp
	push ax
	push bx
	push cx
	push dx
	push es
	push di 
	push si

	mov ax,0xb800 ;video mem
	mov es,ax

	mov ax,12 ;x pos
	mov bx,80
	mul bx ;
	add ax,30 ;y pos
	shl ax,1 ;hardcode x and y pos... cuz we dont need to change its pos bar bar. 
	mov di,ax ;
	mov si,over ;score word.
	mov cx,[leng] ; length of score
	mov ah,0x07 ; color of score.
	cld ; moving ahead.
nextchar2:
	lodsb ;load the str into mem  (s) ready to be printed.
	stosw ; printing the s word on the vid mem.
	loop nextchar ; lentgh of our score word.
	pop si
	pop di
	pop es
	pop dx
	pop cx
	pop bx
	pop ax
	pop bp
	ret 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;code for the printing of the bricks;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

bricks_vertical:
	push bp 
	mov bp,sp ;parameter pushing of sp to bp.
	push ax
	push bx
	push cx
	push dx
	push es
	push di
	mov ax,0xb800
	mov es,ax
	mov ax,[bp+6] ;x pos 
	mov bx,80 
	mul bx
	add ax,[bp+4] ;y pos
	shl ax,1 ; mul by 2 so that it gives us proper cordinates.
	mov di,ax ;
	push di ; making two bricks using one cordinate.
	mov ax,0x6020 
	;mov ax,[col]     ;color code for brown
	mov cx, 5; length of brick is 7.
loop1: 
	mov [es:di],ax
	sub di,160
	loop loop1

	pop di ; using refrence cordinates that was earlier stored in di.
	add di ,14 ; moved 10 cols ahead.

	mov cx,5 ; length 7
	loop2 
	mov [es:di],ax ;second vertical brick 
	sub di,160
	loop loop2 

	pop di
	pop es
	pop dx
	pop cx
	pop bx
	pop ax
	pop bp
	ret 4

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;for movement of the bird;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

clrbird: 
	push cx
	push ax
	call backgnd
	call Score_printing	
	push word[scr]
	call printnum
	mov cx,8 ; number of clouds.
	mov ax,2 ;y position.

skyloop:
	push 6 ;fixed x pos (cloud printed of 6th row.)
	push ax ; y pos.(cols)
	call sky ; cloud subroutine.
	add ax,10 ; shifting the cols at right.
	loop skyloop

	push 20 ; x pos of the brick
	push 65 ; y position of the brick.
	call bricks_vertical ;arguements given to the brick.
    mov ax,0x720	;ax , space
	push ax
	mov ax,8		; no of spaces
	push ax
	mov ax, 15		; y rows
	push ax
	mov ax, 65		; x columns 
	push ax
	mov ax,0x6060  ; colour ascii
	push ax
	call horizontalline
	;push 14 ; x pos of the brick
	;push 60; y position of the brick.
	;call bricks_vertical ;arguements given to the brick.
	mov ax,0x720	;ax , space
	push ax
	mov ax,7		; no of spaces
	push ax
	mov ax, 18		; y rows
	push ax
	mov ax, 65		; x columns 
	push ax
	mov ax,0x6060   ; colour ascii
	push ax
	call horizontalline
	call grass
	call treee
	call boww

	pop ax
	pop cx
	ret 

clrbird2: 
	push cx
	push ax
	call backgnd
	call Score_printing	
	;call printnum
	push word[scr]
	call printnum
	mov cx,8 ; number of clouds.
	mov ax,2 ;y position.

skyloop2:
	push 6 ;fixed x pos (cloud printed of 6th row.)
	push ax ; y pos.(cols)
	call sky ; cloud subroutine.
	add ax,10 ; shifting the cols at right.
	loop skyloop2

	;push 20 ; x pos of the brick
	;push 65 ; y position of the brick.
	;call bricks_vertical ;arguements given to the brick.
   
	call grass
	call treee
	call boww

	pop ax
	pop cx
	ret 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;start;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

start:
	mov dx, 3			;number of tries per game.....!
mainloop: 
	;add byte[scr], 10; printing of score.
	mov cx,59
	mov di,2578
	call sleep
	call sleep
	call clrbird
	call bird

;;;;;;;;;;;;;;;;;;;;;for making it ready to move first (left movement) ;;;;;;;;;;;;;;;;;;;;;;;;;;
	mov ah, 0
	int 0x16
	cmp al, 97 ;left arrow ki.
	jnz exit1
	
lo99: 

	call sleep
	call sleep
	call clrbird
	call bird
	sub di,2
	cmp di, 2570			; thora sa peehe chala jaiga
	jne lo99
	
;;;;;;;;;;;;;;;;;its our choice to move it wherever we want but first we are bound to make it ready to move by going a bit left ;;;;;;;;;
;;;;;;;;;;;;;;;;;if we simply try to go left or try to go right or even try to hit the bricks, the code will end;;;;;;;;;;;;;;;;;;;;;;;;;

	
;;;;;;;;;;;;;;;;;;;for making its position specified.towards up;;;;;;;;;;;;;;;;;;;;;;;;
up:	
	mov ah, 0
	int 0x16
	cmp al, 119
	jnz down
	jmp lo10

;; the purpose of the label blow is that the flow will be stepwise (from )
exit1:
	jmp exit
	
lo10: 

	call sleep
	call sleep
	call clrbird
	call bird
	sub di,160
	cmp di, 2250
	jne lo10
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;down movement ;;;;;;;;;;;;;;;;;;;;;;;;;;;	

down:
	;mov ah, 0
	;int 0x16
	cmp al, 115
	jnz jump;jmp

lo11: 

	call sleep
	call sleep
	call clrbird
	call bird
	add di,160
	cmp di, 2890
	jne lo11
	
	
;;;;;;;;;;;;;;;;;;for making it go ahead. moving right;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	
	
jump:
	mov ah, 0
	int 0x16
	cmp al, 100
	jnz exit

lo9: 

	call sleep
	call sleep
	call clrbird
	call bird
	add di,2
	loop lo9
	
	
	;;for brick breaking we are simply vanishing the bricks the moment it reaches the brick;;;;;;;;;;;
	cmp cx, 0
	je go
go:
	call clrbird2
	call sleep
	call sleep
	call sleep
	call sleep
	call sleep
	call sleep
	;call bird
	
	
	add byte[scr], 10; printing of score.
	sub dx, 1
	cmp dx, 0
	
	;;;;;;;;;;;;;;;;;;;;;;;;;increasing the score by 10 each time it hits the brick.
	
	jne mainloop
exit:
		call backgnd
		call Score_printing
		push word[scr]
		call printnum
		call gameover
		mov ax, 0x4c00 ; terminate program
		int 21h