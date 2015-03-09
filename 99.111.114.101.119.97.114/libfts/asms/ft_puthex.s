; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_puthex.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/02/01 04:37:51 by mngomane          #+#    #+#              ;
;    Updated: 2015/02/01 04:37:51 by mngomane         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section		.text
	global	_ft_puthex

_ft_puthex:
_init:
	sub		rsp, 8
	mov		[rsp - 8], rdi
	mov		rdi, rsi
_write:
	mov		rsi, rsp
	sub		rsi, 5
	mov		rax, 0x2000004
	mov		rdx, 1
	syscall

	mov		rsi, rsp
	sub		rsi, 6
	mov		rax, 0x2000004
	mov		rdx, 1
	syscall

	mov		rsi, rsp
	sub		rsi, 7
	mov		rax, 0x2000004
	mov		rdx, 1
	syscall

	mov		rsi, rsp
	sub		rsi, 8
	mov		rax, 0x2000004
	mov		rdx, 1
	syscall
_clear:
	add		rsp, 8
_exit:
	ret
