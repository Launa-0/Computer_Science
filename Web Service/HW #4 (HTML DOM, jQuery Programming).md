HTML-DOM-Lab(lecture 6)의 Top5 CDs 예제 프로그램에 아래와 같은 기능을 추가로 구현하되, HTML-DOM API와 jQuery API를 각각 사용해서 두 가지 버전으로 작성하시오.

(HTML-DOM/js/top5.js와 jQuery/js/top5-jq.js 프로그램을 각각 아래와 같이 수정함)

 

• 상단("cds" div)에 있는 이미지들을 선택하여 하단("top5" div)으로 이동한 후, 버튼 클 릭 시 하단의 모든 이미지들을 상단의 원래 위치(제자리)로 복귀함

- startOver() 함수 수정

• 상단("cds" div)에 있는 이미지들을 선택하여 하단("top5" div)으로 이동한 후, 하단의 각 이미지를 클릭 시 상단의 원래 위치(제자리)로 복귀함

-moveToOriginalPosition() 함수 구현

 

- 제출방법: 

1. top5.js와 top5-jq.js에서 작성한 startOver() 및 moveToOriginalPosition()의 코드들을 과제 게시글 내에 순서대로 copy & paste 함

2. top5.js와 top5-jq.js 파일을 과제 게시글에 파일로 첨부함

 

 

교수님 코드

1. HTML DOM API 이용
 
function addToTop5() {
...
imgElement.onclick = moveToOriginalPosition; // 선택된 이미지를 제자리로 이동시킴
...
}
 
function startOver() {
var cds = document.getElementById("cds");
var top5Element = document.getElementById("top5");
while (top5Element.hasChildNodes()) {
var firstChild = top5Element.firstChild;
if (firstChild.nodeName.toLowerCase() == "img") {
var imgElement = firstChild;
var cdImages = cds.getElementsByTagName("img");
// cds의 <img>들 중 id 값이 imgElement의 id 값보다 크면서 가장 가까운 것을 찾음
for (var i = 0; i < cdImages.length; i++) {
if (Number(cdImages[i].id) > Number(imgElement.id))
break;
}
 
// imgElement를 cds의 제 위치에 삽입 (주의: imgElement가 마지막 이미지인 경우)
if (i == cdImages.length) {
cds.appendChild(imgElement);
} else {
cds.insertBefore(imgElement, cdImages[i]);
}
 
// imgElement에 대해 onclick 이벤트 핸들러 재설정
imgElement.onclick = addToTop5;
} else { // <span>
top5Element.removeChild(firstChild);
}
}
 
function moveToOriginalPosition() { // 선택된 이미지를 제자리로 이동시킴
var imgElement = this; // 선택된 <img> 엘리먼트
var cds = document.getElementById("cds");
var cdImages = cds.getElementsByTagName("img");
 
// cds의 <img>들 중 id 값이 imgElement의 id 값보다 크면서 가장 가까운 것을 찾음
for (var i = 0; i < cdImages.length; i++) {
if (Number(cdImages[i].id) > Number(imgElement.id))
break;
}
 
// imgElement의 순위를 나타내는 <span>을 삭제
var top5Element = imgElement.parentNode;
top5Element.removeChild(imgElement.previousSibling);
 
var nextSpan = imgElement.nextSibling; // 다음 <span> 노드를 미리 구함
 
// imgElement를 cds의 제 위치에 삽입 (주의: imgElement가 마지막 이미지인 경우)
if (i == cdImages.length) {
cds.appendChild(imgElement);
} else {
cds.insertBefore(imgElement, cdImages[i]);
}
 
// imgElement에 대해 onclick 이벤트 핸들러 재설정
imgElement.onclick = addToTop5;
 
// top5 아래의 imgElement 다음에 있었던 이미지들의 순위 값만 변경
for (var node = nextSpan; node != null; node = node.nextSibling) {
if (node.nodeName.toLowerCase() == "span") {
node.textContent = Number(node.textContent) - 1; // 순위 값을 1 감소
}
}
 
/* 또는 아래와 같이 구현 가능: top5아래의 모든 이미지들의 순위 값을 재계산하여 변경
 
var rank = 1;
 
for (var i = 0; i < top5Element.childNodes.length; i++) {
 
if (top5Element.childNodes[i].nodeName.toLowerCase() == "span") {
 
top5Element.childNodes[i].innerHTML = rank;
 
rank++;
 
}
 
}
 
*/
}
 
 
2. jQuery 이용
 
function addToTop5() {
...
$(imgElement).off("click");
$(imgElement).click(moveToOriginalPosition); // 선택된 이미지를 제자리로 복귀(이동)시킴
// 또는 $(imgElement).off("click").on("click", moveToOriginalPosition);
...
}
 
function startOver() {
$("#top5 > img").each(function() {
var top5Img = this;
$("#cds > img").each(function() { // <img>들에 대해 순서대로 funciton 호출
var curImg = this; // this는 function이 호출된 <img>
if (Number(curImg.id) > Number(top5Img.id)) { // imgElement를 삽입할 다음 형제 <img> 발견
$(top5Img).insertBefore(curImg); // imgElement를 curImg 앞에 삽입
return false; // false return 시 each()의 반복문 실행이 중단됨 (다음 <img>들은 무시)
}
});
 
// cds의 <img>들 중 id 값이 top5Img보다 큰 것이 없을 경우,
// 위에서 cds의 자식으로 삽입되지 않으므로 별도로 처리 필요
if ($(top5Img).parent().attr("id") == "top5") { // imgElement가 아직 top5 아래에 위치
$("#cds").append(top5Img); // cds의 마지막 자식으로 추가
}
 
// top5Img에 대해 onclick 이벤트 핸들러 재설정
$(top5Img).off("click").on("click", addToTop5);
})
 
$("#top5").children().remove(); // top5의 자식들을 모두 삭제
}
 
function moveToOriginalPosition() { // 선택된 top5 아래의 하나의 이미지를 제자리로 이동시킴
var imgElement = this; // 선택된 <img> 엘리먼트
 
// imgElement의 순위를 나타내는 <span>을 삭제
$(imgElement).prev().remove();
 
var nextSpans=$(imgElement).nextAll("span"); // 다음 <span> 노드들을 미리 구함
 
// cds의 <img>들 중 id 값이 imgElement의 id 값보다 크면서 가장 가까운 것을 찾음
$("#cds > img").each( function(){ // <img>들에 대해 순서대로 funciton 호출
var curElement = this; // this는 function이 호출된 <img>
if (Number(imgElement.id) < Number(curElement.id)) { // imgElement를 삽입할 다음 형제 <img> 발견
$(imgElement).insertBefore(curElement); // imgElement를 curImg 앞에 삽입
return false; // false return: each()의 반복문 실행이 중단됨 (다음 <img>들은 무시)
}
});
 
// cds의 <img>들 중 id 값이 imgElement보다 큰 것이 없을 경우 위에서 처리되지 않으므로 별도로 처리
if ($(imgElement).parent().attr("id") == "top5") { // imgElement가 아직 top5 아래에 위치
$("#cds").append(imgElement); // cds의 마지막 자식으로 추가
}
 
// imgElement에 대해 onclick 이벤트 핸들러 재설정
$(imgElement).off("click").on("click", addToTop5);
 
// top5 아래의 imgElement 다음에 있었던 이미지들의 순위 값만 변경
$(nextSpans).each( function() {
$(this).text($(this).text() - 1);
});
 
/*
 
// 또는 top5 아래의 모든 이미지들의 순위 값 변경
 
$("#top5 > span").each( function(i) { // i: index 값 (0, 1, 2, ...)
 
$(this).text(i + 1); // 1, 2, 3, ...
 
});
 
*/
}
