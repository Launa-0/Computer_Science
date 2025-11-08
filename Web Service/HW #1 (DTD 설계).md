문제 및 보충설명 자료: Lecture 2 강의자료 게시글 참조
웹서비스 실습 #1: DTD 설계 도서에 관한 정보를 XML로 표현하고 관리하기 위해 Book Markup Language(BookML) v1.0을 정의하고자 한다.
1. 아래의 요구사항들을 최대한 만족하도록 BookML DTD를 설계하시오.
2. 설계한 DTD를 따르는 유효한 BookML 문서의 예를 작성하시오. (각 요구사항에 대한 예들을 포함)
가. 기본 요구사항
R1	BookML 문서는 도서들의 목록과 도서 분류 체계로 구성된다.
R2	각 도서는 제목, 저자, 출판사, 출판일, 가격, 할인율, 페이지수, 평점, 분야(category)에 대한 정보 를 갖고, 추가적으로 개정일, 표지그림, 책소개, 독자리뷰를 가질 수 있다. 번역서는 원제목과 역 자 정보도 있다. 저자와 분야, 개정일은 여러 개가 존재할 수 있고, 독자리뷰는 최대 50개까지만 가능하다.
R3	도서의 식별자는 ISBN10 (isbn:xxxxxxxxx-x) 또는 ISBN13 (isbn:978(또는 979)-xxxxxxxxx-x) 형식을 사용하고, 도서마다 서로 다른 유일한 값을 갖는다. (주의: DTD에서 값의 형식 지정 불가)
R4	도서의 출판일과 개정일은 연, 월, 일로 구성된다. 연도는 1900~2025 사이의 값을 갖고, 월과 일 은 각각 01~12, 01~31 사이의 값을 갖는다. (주의: DTD에서 값의 범위 지정 불가)
R5	가격은 정가와 판매가(할인가)로 구분되고 양수 값을 갖는다. 가격은 원, 달러, 엔으로 표시된다. 원화인 경우 생략 가능하다(즉, 통화가 생략될 경우 원화로 간주함). 할인율(%)은 0이상 80이하 의 값을 갖는다. (주의: DTD에서 값의 범위 지정 불가)
R6	페이지수는 1이상 2000이하의 값을 갖고, 평점(rating)은 1~5 사이의 실수 값을 갖는다.
R7	도서가 속한 분야 정보는 별도로 정의되는 도서 분류 체계에 포함된 분야(들)에 대응되어야 한 다 (즉, 도서 분류 체계에 존재하는 분야(들)만 이용 가능).
R8	도서의 표지그림은 외부의 이미지 파일을 지정해야 하며, 파일의 포맷(JPEG, GIF, PNG 등)과 파 일을 읽고 출력할 수 있는 응용 프로그램(예: imageViewer.exe)을 나타내야 한다.
R9	다운로드 받을 수 있는 전자책(eBook) 도서는 위 R2에 나열된 정보들 뿐만 아니라 파일형식과 파일크기, 이용기간이 추가된다. 이용기간은 제한이 없을 경우 생략 가능하다.
R10	전자책의 파일형식은 EPUB, PDF, StreamText, StreamImage 중 하나의 값을 갖는다. 파일크기는 실수 값이고 단위가 있다(예: 985 KB, 1.45 MB 등). 이용기간은 일 수로 정의된다.
R11	새로 나온 신간 전자책(newEBook)은 이용기간이 최대 3주이고, 개정일은 존재할 수 없다.
R12	도서 분류 체계는 문학, 인문, 사회, 과학, 유아, 컴퓨터 등 다양한 분야를 포함할 수 있다. 각 분 야는 이름뿐만 아니라 식별자를 갖고, 다시 세부 분야로 나뉠 수 있다(예: 문학은 소설, 시, 희곡 등으로 세분화될 수 있고, 소설은 다시 한국소설, 영미소설, 장르소설 등으로 더 세분화 가능). 각 분야의 이름과 분류 체계의 구성은 DTD 문서에서 미리 정의되지 않고 BookML 문서마다 사 용자에 의해 자유롭게 정의될 수 있어야 한다.
 

나. 기타 요구사항
1. DTD를 외부 파일로 정의하고 이 파일을 참조하는 BookML 문서를 작성함

2. DTD에서 내부 parameter entity와 내부 일반 parsed entity를 하나 이상 정의하여 사용함

3. BookML 문서에서 built-in entity를 한 번 이상 사용함

4. DTD에서 각 요구사항에 관련된 부분에 대해 주석으로 요구사항 번호를 표시하고 간략히 설명함

5. BookML 예제 문서에 대해 유효성 검사를 실시하여 오류가 없음을 확인(증명)함

제출방법: DTD 문서와 BookML 예제 문서, 두 문서에 대한 유효성 검사 결과 화면(capture image)을 제출함
 
참고: BookML 문서의 예 (bookCatalog.xml)  
<?xml version="1.0" encoding="UTF-8"?> 
<!DOCTYPE catalog SYSTEM "bookML.dtd"> 
<catalog>     
    <bookList>                   
        <book id="isbn:895468000-3" categories="c101-1-1">     <!-- 문학/소설/한국소설에 속함 --> 
            <title>이토록 평범한 미래</title>  
            <author>김연수</author> 
            <publisher>문학동네</publisher> 
            <publishDate year="2022" month="10" day="07" />         
<!-- 다음과 같은 형식도 가능: 
<publishDate> 
<year>2022</year><month>10</month><day>07</day>    
                </publishDate> --> 
<revisionDate year="2023" month="11" day="15" />      
            <price currency="won"> 
                <listPrice>14000</listPrice> 
                <salesPrice discountRate="10">12600</salesPrice> 
            </price> 
<!-- 다음과 같은 형식도 가능: 
                    <price currency="won" listPrice="14000" salesPrice="12600" discountRate="10" /> -->            
            <pages>276</pages>             
<rating>4.8</rating> 
            <coverImage src="https://image.yes24.com/goods/113737429/XL" type="jpeg" /> 
            <description>김연수 9년 만의 신작 소설집. 종말 이후의 사랑에 대한 여덟 편의 이야기. 작가가 
최근 2~3년간 집중적으로 단편 작업에 매진한 끝에 선보이는 소설집으로, '시간'을 인식하는 김연수의 변화된 
시각을 확인할 수 있게 한다. 김연수는 과거에서 미래를 향해 흐르는 것으로만 여겨지는 시간을 다르게 정의
함으로써 우리가 현재의 시간을, 즉 삶을 새롭게 상상할 수 있는 가능성을 아름답고 서정적인 언어로 설득해
낸다. 특별한 점은 그 가능성이 '이야기'의 형태로 전달된다는 것이다. … 
</description> 
<review>"우리가 달까지 갈 수는 없지만 갈 수 있다는 듯이 걸어갈 수는 있다. 달이 어디에 있
는지 찾을 수만 있다면. 마찬가지로 우리는 달까지 걸어가는 것처럼 살아갈 수 있다. 희망의 방향만 찾을 수 
있다면." (-&lt;진주의 결말&gt; 중에서) 어떤 희망의 방향을 찾는 일은 때로 쉽고 어렵다. 이런 소설을 읽으
면서 작은 격려와 응원을 받는 기분이다. 좋은 소설에 대해, 우리가 기다렸던 소설이 이런 게 아닐까 싶
다.</review> 
 <review>…</review> … 
        </book> 
        <eBook id="isbn:978-893497246-4" categories="c102-1 c103-2">  <!-- 전자책; 인문/일반교양, 역사/
세계사 분야에 속함 --> 
            <title>사피엔스</title>  
            <originalTitle>Sapiens: A Brief History of Humankind & Earth</originalTitle> <!--원제--> 
            <author>유발 하라리</author> 
            <translator>조현욱</translator>     <!-- 역자 --> 
            <publisher>김영사</publisher> 
            <publishDate year="2014" month="05" day="19" /> 
<price>     <!-- currency="won" --> 
   <listPrice>12000</listPrice> 
   <salesPrice discountRate="20">9600</salesPrice> 
  </price>  
<pages>241</pages><rating>4.2</rating> 
            <description>변방의 유인원 호모 사피엔스는 어떻게 세상의 지배자가 되었는가? 수렵채집을 하
던 우리 조상들은 어떻게 한 곳에 모여 도시와 왕국을 건설하였는가? 인간은 왜 지구 역사상 가장 치명적인 
동물이 되었는가? 과학은 모든 종교의 미래인가? 인간의 유효기간은 언제까지인가? 멀고먼 인류의 시원부터 
인지혁명, 농업혁명, 과학혁명을 거쳐 끊임없이 진화해온 인간의 역사를 생물학, 경제학, 종교학, 심리학, 철학 
등 여러 학문의 경계를 넘나들며 다양하고 생생하게 조명한 전인미답의 문제작. 호모 사피엔스부터 인공지능
까지, 기나긴 역사의 시간을 한 권으로 써내려간 문명 항해기. </description> 
  <format value="EPUB" />         <!-- eBook 파일형식 --> 
            <size unit="MB">26.60</size>    <!-- eBook 파일크기 --> 
            <period>30</period>        <!-- eBook 이용기간 --> 
        </eBook> 
         … 
<newEBook id="isbn:979-119238935-6" categories="c102-2">    <!-- 신간 전자책; 인문/심리학 --> 
      <title>마음의 기술: 부정적 감정을 지우는 효과적인 뇌 사용법</title> 
<originalTitle>Devenez Votre Propre Psy</originalTitle>   
      <author>안-엘렌 클레르</author> 
       ... 
      <publishDate year="2024" month="11" day="18" />  
      <revisionDate year="2025" month="03" day="10" />    <!-- 오류: 개정일 존재 불가! --> 
       … 
      <format value="EPUB" /> 
      <size unit="MB">43.42</size> 
      <period>25</period>                             <!-- 오류: 이용기간은 3주 이내! --> 
</newEBook> 
       ... 
    </bookList> 
    <bookCategory> 
        <category cid="c101" name="문학"> 
            <category cid="c101-1" name="소설">  
                <category cid="c101-1-1" name="한국소설"> ... </category> 
                <category cid="c101-1-2" name="영미소설"> ... </category>         
                ... 
            </category>  
            <category cid="c101-2" name="시"> ... </category> 
            <category cid="c101-3" name="희곡"> ... </category>  
            ... 
        </category> 
        <category cid="c102" name="인문">  
            <category cid="c102-1" name="철학/사상"> ... </category> 
<category cid="c102-2" name="심리학"> ... </category> 
            ...             
        </category> 
        <category cid="c103" name="역사">  
            <category cid="c103-1" name="한국사"> ... </category> 
            <category cid="c103-2" name="세계사"> ... </category> 
            ...             
        </category> 
        ... 
    </bookCategory> 
</catalog>

 
다음 결과물들을 제출함  
DTD 문서 (Eclipse 화면 캡처)
BookML 예제 문서 (XML file)
DTD 문서에 대한 유효성 검사 결과 화면 (Eclipse 화면 캡처)
BookML 예제 문서에 대한 유효성 검사 결과 화면 (Eclipse 화면 캡처) 
 

 
제출방법
게시글을 생성하고, 1, 3, 4번의 화면 캡처 이미지들을 순서대로 게시글 안에 포함시킴("이미지 삽입/수정" 아이콘 이용)
2번 BookML 예제 문서는 파일을 첨부함
 
주의사항
1, 3, 4번의 캡처 이미지들을 게시물 안에 포함시키고 별도의 파일을 첨부하지 말 것(확인 X)
캡처 이미지는 크기를 적절히 조정해서 내용이 식별 가능하도록 함
3, 4번의 유효성 검사 결과 화면은 편집창에 열린 DTD나 XML 문서의 내용 위에 유효성 검사 결과 팝업창이 함께 보이도록 캡처해야 함 (팝업창만 캡처할 경우 미인정)
 

https://sseungji.tistory.com/14

 
DTD 구성요소 (1)

엘리먼트 선언 contents model - #PCDATA // XML parser가 해석하는 문자 데이터 - children - mixed contents category - empty - any 엘리먼트 선언 실습 1) bookML 문서는 도서들의 목록과 도서 분류체계로 구성된다 bookLis

sseungji.tistory.com
이 블로그 글을 많이 참고했다

 

내 답안은 너무 에러가 많아서 교수님 답안

 

<!-- parameter entity 선언 -->
<!ENTITY % commonBookInfo1 "title, originalTitle?, author+, translator?, publisher, publishDate">
<!ENTITY % commonBookInfo2 "price, pages, rating, coverImage?, description?, review*">
<!ENTITY % bookAttrs "id ID #REQUIRED 
 categories IDREFS #REQUIRED">
<!ENTITY % dateAttrs "year CDATA #REQUIRED 
 month (01|02|03|04|05|06|07|08|09|10|11|12) #REQUIRED
 day CDATA #REQUIRED">
 
<!-- 내부 일반 parsed entity 선언 -->
<!ENTITY favorateAuthor "김연수">
 
<!-- 표지그림의 속성을 위한 Notation 선언 -->
<!NOTATION gif PUBLIC "image/gif" "photoshop.exe">
<!NOTATION bmp PUBLIC "image/bmp" "photoshop.exe">
<!NOTATION jpeg PUBLIC "image/jpeg" "mspaint.exe">
  
<!-- root element 선언 -->
<!ELEMENT catalog (bookList, bookCategory)>
 
<!-- book list -->
<!ELEMENT bookList (book*, eBook*, newEBook*)> <!-- 또는 (book|eBook|newEBook)* -->
 
<!-- 세 종류의 도서 관련 element 및 attribute 선언 -->
<!ELEMENT book (%commonBookInfo1;, revisionDate?, %commonBookInfo2;)> 
<!ELEMENT eBook (%commonBookInfo1;, revisionDate?, %commonBookInfo2;, format, size, period)>
<!ELEMENT newEBook (%commonBookInfo1;, %commonBookInfo2;, format, size, period)>
 
<!ATTLIST book %bookAttrs;>
<!ATTLIST eBook %bookAttrs;>
<!ATTLIST newEBook %bookAttrs;>
 
<!-- book's children --> 
<!ELEMENT title (#PCDATA)>
<!ELEMENT originalTitle (#PCDATA)>
<!ELEMENT author (#PCDATA)>
<!ELEMENT translator (#PCDATA)>
<!ELEMENT publisher (#PCDATA)>
<!ELEMENT publishDate EMPTY>
<!ATTLIST publishDate %dateAttrs;>
<!ELEMENT revisionDate EMPTY>
<!ATTLIST revisionDate %dateAttrs;>
 
<!-- 가격 -->
<!ELEMENT price (listPrice, salesPrice)>
<!ATTLIST price currency (won|dollar|yen) "won">
<!ELEMENT listPrice (#PCDATA)>
<!ELEMENT salesPrice (#PCDATA)>
<!ATTLIST salesPrice discountRate CDATA #IMPLIED> 
 
<!ELEMENT pages (#PCDATA)>
<!ELEMENT rating (#PCDATA)>
<!ELEMENT coverImage (#PCDATA)>
<!ATTLIST coverImage src CDATA #REQUIRED 
 type NOTATION (gif|bmp|jpeg) "gif">
<!ELEMENT description (#PCDATA)>
<!ELEMENT review (#PCDATA)>
 
<!-- eBook's children -->
<!ELEMENT format EMPTY>
<!ATTLIST format value (EPUB|pdf|StreamText|StreamImage) "EPUB">
<!ELEMENT size (#PCDATA)>
<!ATTLIST size unit (B|KB|MB|GB) "KB">
<!ELEMENT period (#PCDATA)>
 
<!-- book category --> 
<!ELEMENT bookCategory (category*)> <!-- 또는 (#PCDATA|category)* -->
<!ELEMENT category (category*)> 
<!ATTLIST category cid ID #REQUIRED
 name CDATA #REQUIRED>