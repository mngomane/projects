; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/01/28 19:46:29 by mngomane          #+#    #+#              ;
;    Updated: 2015/01/28 19:46:29 by mngomane         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section		.text
	global	_ft_strdup

extern		_malloc, _ft_strlen

_ft_strdup:
	sub		rsp, 16
	mov		[rsp - 8], rdi
	call	_ft_strlen
	mov		rcx, rax
	mov		rdi, rcx
	mov		[rsp - 16], rcx
	call	_malloc
	mov		rcx, rsp
	sub		rcx, 16
	mov		rdi, rax
	mov		rsi, [rsp - 8]
	sub		rsi, 8
	rep
	movsb
_clear:
	add		rsp, 16
	ret
