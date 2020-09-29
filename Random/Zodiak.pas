program ideone;
var
	x,y : integer;
begin
	readln(x,y);
	
	case x of
	1 : begin
			case y of 
			1..19 : writeln('Capricorn');
			20..31 : writeln('Aquarius');
			end;
		end;
	2 : begin
			case y of
			1..18 : writeln('Aquarius');
			19..29 : writeln('Pisces');
			end;
		end;
	3 : begin
			case y of
			1..20 : writeln('Pisces');
			21..31 : writeln('Aries');
			end;
		end;
	4 : begin
			case y of
			1..19 : writeln('Aries');
			20..30 : writeln('Taurus');
			end;
		end;
	5 : begin
			case y of
			1..20 : writeln('Taurus');
			21..31 : writeln('Gemini');
			end;
		end;
	6 : begin
			case y of
			1..20 : writeln('Gemini');
			21..30 : writeln('Cancer');
			end;
		end;
	7 : begin
			case y of
			1..22 : writeln('Cancer');
			23..31 : writeln('Leo');
			end;
		end;
	8 : begin
			case y of
			1..22 : writeln('Leo');
			23..31 : writeln('Virgo');
			end;
		end;
	9 : begin
			case y of
			1..22 : writeln('Virgo');
			23..30 : writeln('Libra');
			end;
		end;
	10 : begin
			case y of
			1..22 : writeln('Libra');
			23..31 : writeln('Scorpio');
			end;
		end;
	11 : begin
			case y of
			1..21 : writeln('Scorpio');
			22..30 : writeln('Sagittarius');
			end;
		end;
	12 : begin
			case y of
			1..21 : writeln('Sagittarius');
			22..31 : writeln('Capricorn');
			end;
		end;
	end;
	
end.
